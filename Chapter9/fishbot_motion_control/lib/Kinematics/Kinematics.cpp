#include "Kinematics.h"
void Kinematics::set_motor_param(uint8_t id, float per_pulse_distance)
{
    motor_param_[id].per_pulse_distance = per_pulse_distance;
    /* 电机每个脉冲前进
    距离*/
}
void Kinematics::set_wheel_distance(float wheel_distance)
{
    wheel_distance_ = wheel_distance;
}
// 传入电机的编号 id 返回该编号电机的速度
int16_t Kinematics::get_motor_speed(uint8_t id)
{
    return motor_param_[id].motor_speed;
}
/**
 * @brief 更新电机速度和编码器数据
 * @param current_time 当前时间（单位：毫秒）
 * @param left_tick 左轮编码器读数
 * @param right_tick 右轮编码器读数
 */
void Kinematics::update_motor_speed(uint64_t current_time, int32_t motor_tick1, int32_t motor_tick2,
                                    int32_t motor_tick3, int32_t motor_tick4)
{
    uint64_t dt = current_time - motor_param_[0].last_update_time;
    // uint32_t dt = millis() - motor_param_[0].last_update_time;
    // Serial.printf("dt=%f ms\n ", static_cast<float>(dt));
    static int32_t dticks[4];
    static int32_t motor_ticks[4];

    motor_ticks[0] = motor_tick1;
    motor_ticks[1] = motor_tick2;
    motor_ticks[2] = motor_tick3;
    motor_ticks[3] = motor_tick4;

    for (int index = 0; index < 4; index++)
    {
        // ticks数量计算
        dticks[index] = motor_ticks[index] - motor_param_[index].last_encoder_tick;
        // 轮子速度计算
        motor_param_[index].motor_speed = dticks[index] * (motor_param_[index].per_pulse_distance / dt) * 1000.0f;
        motor_param_[index].last_encoder_tick = motor_ticks[index];
        motor_param_[index].last_update_time = current_time;
        // motor_param_[index].last_update_time = millis();
    }
    // Serial.printf("motor_ticks[3]: %d, last_encoder_tick[3]: %d\n", motor_ticks[3], motor_param_[3].last_encoder_tick);
    // Serial.printf("dticks[3]: %d\n", dticks[3]);
    // Serial.printf("dt: %u ms\n", dt);
    // 打印所有电机的速度数据
    // Serial.printf("speed1=%f mm/s, speed2=%f mm/s, speed3=%f mm/s, speed4=%f mm/s\n",
    //               motor_param_[0].motor_speed, motor_param_[1].motor_speed,
    //               motor_param_[2].motor_speed, motor_param_[3].motor_speed);
    // 更新里程计信息
    update_odom(dt);
}
/**
 * @brief 正运动学计算，将左右轮的速度转换为线速度和角速度
 * @param left_speed 左轮速度（单位：毫米/秒）
 * @param right_speed 右轮速度（单位：毫米/秒）
 * @param[out] out_linear_speed 线速度（单位：毫米/秒）
 * @param[out] out_angle_speed 角速度（单位：弧度/秒）
 */
void Kinematics::kinematic_forward(float wheel1_speed, float wheel2_speed,
                                   float wheel3_speed, float wheel4_speed, float &linear_x_speed, float &linear_y_speed, float &angular_speed)
{
    linear_x_speed = (wheel1_speed + wheel2_speed + wheel3_speed +
                      wheel4_speed) /
                     4.0f;
    linear_y_speed = 0.0f;
    angular_speed = (wheel2_speed + wheel4_speed - wheel1_speed -
                     wheel3_speed) /
                    (2.0f * wheel_distance_);
}
/**
 * @brief 逆运动学计算，将线速度和角速度转换为左右轮的速度
 * @param linear_speed 线速度（单位：毫米/秒）
 * @param angle_speed 角速度（单位：弧度/秒）
 * @param[out] out_left_speed 左轮速度（单位：毫米/秒）
 * @param[out] out_right_speed 右轮速度（单位：毫米/秒）
 */
void Kinematics::kinematic_inverse(float linear_x_speed, float linear_y_speed, float angular_speed, float &out_wheel_speed1, float &out_wheel_speed2, float &out_wheel_speed3, float &out_wheel_speed4)
{
    out_wheel_speed1 = linear_x_speed - (angular_speed * wheel_distance_ / 2);
    out_wheel_speed3 = linear_x_speed - (angular_speed * wheel_distance_ / 2);
    out_wheel_speed2 = linear_x_speed + (angular_speed * wheel_distance_ / 2);
    out_wheel_speed4 = linear_x_speed + (angular_speed * wheel_distance_ / 2);
}
odom_t &Kinematics::get_odom() { return odom_; }
// 用于将角度转换到 -π 到 π 的范围内
void Kinematics::TransAngleInPI(float angle, float &out_angle)
{
    // 如果 angle 大于 π，则将 out_angle 减去 2π
    if (angle > PI)
    {
        out_angle -= 2 * PI;
    }
    // 如果 angle 小于 -π，则将 out_angle 加上 2π
    else if (angle < -PI)
    {
        out_angle += 2 * PI;
    }
}
void Kinematics::update_odom(uint64_t dt)
{
    static float linear_x_speed, linear_y_speed, angular_speed;
    float dt_s = (float)(dt / 1000.0f); // 将 dt 转换为秒
    // Serial.printf("dt: %f s\n", dt_s);
    this->kinematic_forward(motor_param_[0].motor_speed,
                            motor_param_[1].motor_speed,
                            motor_param_[2].motor_speed,
                            motor_param_[3].motor_speed,
                            linear_x_speed,
                            linear_y_speed,
                            angular_speed);
    Serial.printf("[update odom] linear_x_speed=%f mm/s, linear_y_speed=%f mm/s, angular_speed=%f mm/s\n",
        linear_x_speed, linear_y_speed, angular_speed);
    odom_.angular_speed = angular_speed;
    odom_.linear_x_speed = linear_x_speed / 1000.0f; // /1000（mm/s 转 m/s）
    odom_.linear_y_speed = linear_y_speed / 1000.0f; // /1000（mm/s 转 m/s）
    /*更新 x 和 y 轴上移动的距离*/
    odom_.x += odom_.linear_x_speed * cos(odom_.yaw) * dt_s -
               odom_.linear_y_speed * sin(odom_.yaw) * dt_s;
    odom_.y += odom_.linear_y_speed * cos(odom_.yaw) * dt_s +
               odom_.linear_x_speed * sin(odom_.yaw) * dt_s;
    odom_.yaw += odom_.angular_speed * dt_s;
    Kinematics::TransAngleInPI(odom_.yaw, odom_.yaw);
}