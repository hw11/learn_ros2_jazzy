#include "PidController.h"
#include "Arduino.h"

//
PidController::PidController(float kp, float ki, float kd)
{
    reset();                // 初始化控制器
    update_pid(kp, ki, kd); // 更新 PID 参数
}
float PidController::update(float current)
{
    // 计算误差及其变化率
    float error = target_ - current; // 计算误差
    // derivative_ = last_error_ - error;   // 计算误差变化率??
    derivative_ =  error - last_error_;   // 计算误差变化率
    last_error_ = error;
    // 更新上一次误差为当前误差
    // 计算积分项并进行积分限制
    integral_ += error;
    if (integral_ > integral_up_)
    integral_ = integral_up_;
    if (integral_ < -1 * integral_up_)
    integral_ = -1 * integral_up_;
    // 计算控制输出值
    // float output = kp_ * error + ki_ * integral_ + kd_ * derivative_;
    // 控制输出限幅
    // if (output > out_max_)
    //     output = out_max_;
    // if (output < out_min_)
    //     output = out_min_;
    // output_ = output;

    float delta_output = kp_ * error + ki_ * integral_ + kd_ * derivative_;
    output_ += delta_output;
    if (output_ > out_max_)
        output_ = out_max_;
    if (output_ < out_min_)
        output_ = out_min_;
    if (target_ > -10.0f & target_ < 10.0f) // 控制死区： 输出为0
    {
        output_ = 0.0f;
    }
    return output_;
}
void PidController::update_target(float target)
{
    target_ = target; // 更新控制目标值
}
void PidController::update_pid(float kp, float ki, float kd)
{
    reset();  // 重置控制器状态
    kp_ = kp; // 更新比例项系数
    ki_ = ki; // 更新积分项系数
    kd_ = kd; // 更新微分项系数
}
void PidController::reset()
{
    // 重置控制器状态
    target_ = 0.0f;     // 控制目标值
    out_min_ = 0.0f;    // 控制输出最小值
    out_max_ = 0.0f;    // 控制输出最大值
    kp_ = 0.0f;         // 比例项系数
    ki_ = 0.0f;         // 积分项系数
    kd_ = 0.0f;         // 微分项系数
    integral_ = 0.0f;  // 误差累计值
    derivative_ = 0.0f;     // 误差变化率
    last_error_ = 0.0f; // 上一次的误差值
    integral_up_ = 2500.0f;
}
void PidController::out_limit(float out_min, float out_max)
{
    out_min_ = out_min; // 控制输出最小值
    out_max_ = out_max; // 控制输出最大值
}