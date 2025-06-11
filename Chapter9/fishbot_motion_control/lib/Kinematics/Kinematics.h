#ifndef __KINEMATICS_H__ /* 防止头文件被多次包含 */
#define __KINEMATICS_H__
#include <Arduino.h> /* 包含 Arduino 核心库*/

// 定义一个结构体用于存储电机参数
typedef struct
{
    float per_pulse_distance;  /* 单个脉冲对应轮子前进距离 */
    float motor_speed;       /* 当前电机速度 mm/s，计算时使用*/
    int32_t last_encoder_tick; /* 上次电机的编码器读数*/
    uint64_t last_update_time; /* 上次更新数据的时间，单位 ms */
} motor_param_t;

typedef struct
{
    float w;
    float x;
    float y;
    float z;
} quaternion_t;

/**
 * @brief 里程计相关信息，根据轮子速度信息和运动模型推算而来
 *
 */
typedef struct
{
    float x;                 // 坐标 x
    float y;                 // 坐标 y
    float yaw;               // yaw
    quaternion_t quaternion; // 姿态四元数
    float linear_x_speed;    // x 线速度
    float linear_y_speed;    // y 线速度
    float angular_speed;     // 角速度
} odom_t;

/* 定义一个类用于处理机器人运动学 */
class Kinematics
{
public:
    motor_param_t motor_param_[4]; /* 存储四个电机的参数*/
    /* 构造函数，默认实现 */
    Kinematics() = default;
    /* 析构函数，默认实现 */
    ~Kinematics() = default;

    /* 更新里程计数据 */
    void update_odom(uint64_t dt);
    /* 获取里程计数据 */
    odom_t &get_odom();
    /* 用于将角度转换到 -π 到 π 的范围内 */
    static void TransAngleInPI(float angle, float &out_angle);

    /* 设置电机参数，包括编号和每个脉冲对应的轮子前进距离 */
    void set_motor_param(uint8_t id, float per_pulse_distance);
    /* 设置轮子间距*/
    void set_wheel_distance(float wheel_distance);
    /* 逆运动学计算，将线速度和角速度转换为左右轮的速度*/
    void kinematic_inverse(float linear_x_speed, float linear_y_speed,
                           float angular_speed, float &out_wheel1_speed, float &out_wheel2_speed, float &out_wheel3_speed, float &out_wheel4_speed);
    /* 正运动学计算，将左右轮的速度转换为线速度和角速度*/
    void kinematic_forward(float wheel1_speed, float wheel2_speed, float wheel3_speed, float wheel4_speed, float &linear_x_speed, float &linear_y_speed, float &angular_speed);
    /* 更新电机速度和编码器数据*/
    void update_motor_speed(uint64_t current_time, int32_t motor_tick1,
                            int32_t motor_tick2, int32_t motor_tick3, int32_t motor_tick4);
    /* 获取电机速度*/
    int16_t get_motor_speed(uint8_t id);

private:
    uint64_t last_update_time;     /* 上次更新数据的时间，单位 ms*/
    float wheel_distance_;         /* 轮子间距*/
    odom_t odom_;                  /* 存储里程计信息 */
};
#endif //__KINEMATICS_H__