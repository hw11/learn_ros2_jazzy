#include <Arduino.h>
#include <Esp32PcntEncoder.h>
#include <Esp32McpwmMotor.h>
#include <PidController.h> // 引入 PID 控制器头文件
#include <Kinematics.h>    // 引入运动学头文件

// 引入Micro-ros和wifi相关的头文件
#include <WiFi.h>
#include <micro_ros_platformio.h>
#include <rcl/rcl.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>

#include <geometry_msgs/msg/twist.h>              // 引入几何消息类型的 Twist 消息，用于速度控制
#include <nav_msgs/msg/odometry.h>                // 引入导航消息类型的 Odometry 消息，用于发布里程计信息
#include <micro_ros_utilities/string_utilities.h> // 引入字符串内存分配初始化工具

// 声明一些相关的结构体对象
rcl_allocator_t allocator; // 内存分配器， 用于动态内存分配管理
rclc_support_t support;    //  用于存取时钟，内存分配器和上下文，用于提供支持
rclc_executor_t executor;  // 执行器，用于管理订阅和计时器回调的执行
rcl_node_t node;           // 节点，用于创建和管理 ROS 2 节点

rcl_subscription_t sub_cmd_vel;        // 订阅对象，用于接收速度控制消息
geometry_msgs__msg__Twist cmd_vel_msg; // 用于存储接收到的速度控制消息

rcl_publisher_t pub_odom;         // 发布对象，用于发布里程计消息
nav_msgs__msg__Odometry odom_msg; // 用于存储里程计消息
rcl_timer_t timer;                // 定时器，用于定时发布里程计消息

Esp32PcntEncoder encoders[4]; // 创建一个数组用于存储编码器
Esp32McpwmMotor motor;        // 创建一个名为motor的对象，用于控制电机
PidController pid_controller[4];
Kinematics kinematics;

int64_t last_ticks[4];        // 记录上一次读取的计数器数值
int32_t delta_ticks[4];       // 记录两次读取之间的计数器差值
int64_t last_update_time = 0; // 记录上一次更新时间
float current_speeds[4];      // 记录四个电机的速度
float PID_output[4];          // 用于存储 PID 控制器的输出

float target_linear_x_speed = 0.0;  // 目标 X 方向线速度 毫米每秒
float target_linear_y_speed = 0.0;  // 目标 Y 方向线速度 毫米每秒
float target_angular_speed = 0.05f; // 目标角速度 弧度每秒
float out_speed[4];                 // 用于存储运动学逆解后的速度

// 定时器回调函数
void timer_callback(rcl_timer_t *timer, int64_t last_call_time)
{
    // 完成里程计的发布
    odom_t odom = kinematics.get_odom();     // 获取当前里程计数据
    int64_t stamp = rmw_uros_epoch_millis(); // 获取当前时间戳
    // odom_msg.header.stamp = rclc_uros_time_now(); // 设置消息的时间戳
    odom_msg.header.stamp.sec = static_cast<int32_t>(stamp / 1000);              // 设置秒部分
    odom_msg.header.stamp.nanosec = static_cast<uint32_t>((stamp % 1000) * 1e6); // 设置纳秒部分
    odom_msg.pose.pose.position.x = odom.x;                                      // 设置位置 x
    odom_msg.pose.pose.position.y = odom.y;                                      // 设置位置 y
    odom_msg.pose.pose.position.z = 0.0;                                         // 设置位置 z
    odom_msg.pose.pose.orientation.w = cos(odom.yaw / 2);                        // 设置四元数 w 分量
    odom_msg.pose.pose.orientation.x = 0.0;                                      // 设置四元数 x 分量
    odom_msg.pose.pose.orientation.y = 0.0;                                      // 设置四元数 y 分量
    odom_msg.pose.pose.orientation.z = sin(odom.yaw / 2);                        // 设置四元数 z 分量
    odom_msg.twist.twist.linear.x = odom.linear_x_speed;                         // 设置线速度 x
    odom_msg.twist.twist.linear.y = odom.linear_y_speed;                         // 设置线速度 y
    odom_msg.twist.twist.linear.z = 0.0;                                         // 设置线速度 z
    odom_msg.twist.twist.angular.x = 0.0;                                        // 设置角速度 x
    odom_msg.twist.twist.angular.y = 0.0;                                        // 设置角速度 y
    odom_msg.twist.twist.angular.z = odom.angular_speed;                         // 设置角速度 z
    // 发布里程计消息
    if (rcl_publish(&pub_odom, &odom_msg, NULL) != RCL_RET_OK)
    {
        Serial.println("Failed to publish odometry message");
    }
    // rcl_publish(&pub_odom, &odom_msg, NULL); // 发布里程计消息
}

void twist_callback(const void *msg_in)
{
    Serial.println("twist_callback triggered");
    // 处理接收到的速度控制消息(将收到的消息指针转换为geometry_msgs__msg__Twist 类型)
    const geometry_msgs__msg__Twist *twist_msg = (const geometry_msgs__msg__Twist *)msg_in;

    // 更新目标线速度和角速度
    target_linear_x_speed = twist_msg->linear.x * 1000; // 更新目标 X 方向线速度
    target_linear_y_speed = twist_msg->linear.y * 1000; // 更新目标 Y 方向线速度
    target_angular_speed = twist_msg->angular.z;        // 更新目标角速度
    Serial.printf("Received cmd_vel: linear_x=%f, linear_y=%f, angular_z=%f\n",
                  target_linear_x_speed, target_linear_y_speed, target_angular_speed);

    /// 运动学逆解并设置速度
    kinematics.kinematic_inverse(target_linear_x_speed,
                                 target_linear_y_speed, target_angular_speed,
                                 out_speed[0], out_speed[1],
                                 out_speed[2], out_speed[3]);
    // 设置电机速度
    for (int i = 0; i < 4; i++)
    {
        // 初始化目标速度，单位 mm/s，使用毫米防止浮点运算丢失精度
        pid_controller[i].update_target(out_speed[i]);
    }
}

// 单独创建一个任务，运行micro-ROS 相当于一个线程
void micro_ros_task(void *arg)
{
    // 1. 设置传输协议并延迟一段时间等待设置的完成
    IPAddress agent_ip;
    agent_ip.fromString("192.168.0.103"); // 设置 micro-ROS Agent 的 IP 地址
    set_microros_wifi_transports(const_cast<char *>("luojianqiao"),
                                 const_cast<char *>("Ljq7652999."), agent_ip, 8888); // 设置 micro-ROS 的传输协议为 Wi-Fi
    delay(2000);                                                                     // 等待 2 秒钟，确保传输协议设置完成，等待wifi连接
    // 2. 初始化内存分配器
    allocator = rcl_get_default_allocator(); // 获取默认的内存分配器
    // 3. 初始化 micro-ROS 支持
    rclc_support_init(&support, 0, NULL, &allocator); // 传入支持结构体、参数数量、参数数组和内存分配器
    // 4. 初始化节点
    rclc_node_init_default(&node, "fishbot_motion_control", "", &support); // 创建一个名为 "esp32_node" 的节点
    // 5. 初始化执行器
    unsigned int num_handles = 2;                                             // 定义订阅和计时器数量，注意这是一个要改的参数
    rclc_executor_init(&executor, &support.context, num_handles, &allocator); // 创建一个执行器，最多支持 4 个回调
    // 6. 初始化订阅
    rclc_subscription_init_best_effort(
        &sub_cmd_vel, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(geometry_msgs, msg, Twist), "/cmd_vel"); // 创建一个订阅，订阅名为 "cmd_vel" 的话题
    rclc_executor_add_subscription(
        &executor, &sub_cmd_vel, &cmd_vel_msg, &twist_callback,
        ON_NEW_DATA); // 将订阅添加到执行器中，并指定回调函数 twist_callback，当有新数据时调用
    // 初始化msg
    odom_msg.header.frame_id = micro_ros_string_utilities_set(odom_msg.header.frame_id, "odom");         // 设置里程计消息的帧 ID
    odom_msg.child_frame_id = micro_ros_string_utilities_set(odom_msg.child_frame_id, "base_footprint"); // 设置子帧 ID
    // 7. 初始化发布
    rclc_publisher_init_best_effort(
        &pub_odom, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(nav_msgs, msg, Odometry), "/odom"); // 创建一个发布，发布名为 "odom" 的话题
    // 8. 初始化定时器
    rclc_timer_init_default(
        &timer, &support, RCL_MS_TO_NS(50), timer_callback); // 创建一个定时器，每 50 毫秒调用一次 timer_callback
    rclc_executor_add_timer(&executor, &timer);              // 将定时器添加到执行器中
    // 9. 时间同步
    while (!rmw_uros_epoch_synchronized())
    {
        rmw_uros_sync_session(1000); // 等待时间同步完成
        delay(10);
    }
    // 10. 循环执行器
    rclc_executor_spin(&executor); // 进入循环，执行器将处理订阅和计时器回调
};

// void motorSpeedControl()
// {
//     // 计算时间差
//     uint64_t dt = millis() - last_update_time;
//     Serial.printf("dt=%f ms\n ", dt);
//     // 使用循环处理所有 4 个电机
//     for (int i = 0; i < 4; i++)
//     {
//         // 计算编码器差值
//         delta_ticks[i] = encoders[i].getTicks() - last_ticks[i];
//         // 距离比时间获取速度单位 mm/ms 乘 1000 转换为 mm/s，方便 PID 计算
//         current_speeds[i] = float(delta_ticks[i] * 0.1035095) / dt * 1000;
//         // 更新上一次计数器数值
//         last_ticks[i] = encoders[i].getTicks();
//         // 根据当前速度，更新电机速度值
//         motor.updateMotorSpeed(i, pid_controller[i].update(current_speeds[i]));
//     }
//     // 更新上一次更新时间
//     last_update_time = millis();
//     // 打印所有电机的速度数据
//     Serial.printf("speed1=%f mm/s, speed2=%f mm/s, speed3=%f mm/s, speed4 = % f mm / s\n ",
//                   current_speeds[0], current_speeds[1], current_speeds[2], current_speeds[3]);
// }

void setup()
{
    // 1.初始化串口
    Serial.begin(115200); // 初始化串口通信，设置通信速率为 115200
    motor.attachMotor(0, 5, 4);
    motor.attachMotor(1, 15, 16);
    motor.attachMotor(2, 3, 8);
    motor.attachMotor(3, 46, 9);

    // 2.设置编码器
    encoders[0].init(0, 6, 7);
    encoders[1].init(1, 18, 17);
    encoders[2].init(2, 20, 19);
    encoders[3].init(3, 11, 10);

    // 初始化pid
    for (int i = 0; i < 4; i++)
    {
        // pid_controller[i].update_pid(0.625, 0.125, 0.0);
        pid_controller[i].update_pid(0.1, 0.0, 0.0);
        pid_controller[i].out_limit(-100, 100);
    }

    kinematics.set_wheel_distance(360);
    kinematics.set_motor_param(0, 0.1035095);
    kinematics.set_motor_param(1, 0.1035095);
    kinematics.set_motor_param(2, 0.1035095);
    kinematics.set_motor_param(3, 0.1035095);

    xTaskCreate(micro_ros_task, "micro_ros_task", 10240, NULL, 1, NULL); // 创建一个任务来运行 micro-ROS
}
void loop()
{
    delay(10); // 等待 10 毫秒
    kinematics.update_motor_speed(millis(), encoders[0].getTicks(), encoders[1].getTicks(),
                                  encoders[2].getTicks(), encoders[3].getTicks());
    for (int i = 0; i < 4; i++)
    {
        // 根据当前速度，更新电机速度值
        PID_output[i] = pid_controller[i].update(kinematics.get_motor_speed(i));
        motor.updateMotorSpeed(i, PID_output[i]);
    }
    // motorSpeedControl();
    Serial.printf("[PID output] output1=%f pwm, output2=%f pwm, output3=%f pwm, output4=% f pwm\n ",
                  PID_output[0], PID_output[1], PID_output[2], PID_output[3]);
    Serial.printf("[Target] speed1=%f mm/s, speed2=%f mm/s, speed3=%f mm/s, speed4=% f mm/s\n ",
                  out_speed[0], out_speed[1], out_speed[2], out_speed[3]);
    Serial.printf("[Measurement] speed1=%f mm/s, speed2=%f mm/s, speed3=%f mm/s, speed4=%f mm/s\n",
        kinematics.motor_param_[0].motor_speed, kinematics.motor_param_[1].motor_speed,
        kinematics.motor_param_[2].motor_speed, kinematics.motor_param_[3].motor_speed);
    Serial.printf("[Odom] x, y, yaw-%f, %f, %f\n",
                  kinematics.get_odom().x, kinematics.get_odom().y, kinematics.get_odom().yaw);
}