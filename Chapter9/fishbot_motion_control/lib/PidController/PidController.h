#ifndef __PID_CONTROLLER_H__
#define __PID_CONTROLLER_H__
class PidController
{
public:
    PidController() = default;                   // 默认构造函数
    PidController(float kp, float ki, float kd); // 构造函数，传入 kp、ki、kd
private:
    float target_;
    float out_min_;
    float out_max_;
    float kp_;
    float ki_;
    float kd_;
    float integral_up_ = 2500.0f; // 积分最大值
    // pid中间过程值
    float error_;
    float last_error_;
    float integral_;
    float derivative_;
    float output_;

public:
    float update(float current);                   // 提供当前值返回下次输出值
    void update_target(float target);              // 更新目标值
    void update_pid(float kp, float ki, float kd); // 更新pid参数值
    void reset();                                  // 重置pid
    void out_limit(float out_min, float out_max);  // 设置输出限制
};
#endif
