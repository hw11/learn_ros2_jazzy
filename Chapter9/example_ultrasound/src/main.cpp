#include <Arduino.h>

#define TRIG 21
#define ECHO 47

void setup()
{
    Serial.begin(115200); // 设置串口波特率
    pinMode(TRIG, OUTPUT); 
    pinMode(ECHO, INPUT); 
}
void loop()
{
    //Serial.printf("产生一个 10us 的高脉冲去触发超声波\n");
    digitalWrite(TRIG, HIGH);
    delayMicroseconds(10); // 延时 10 微秒
    digitalWrite(TRIG, LOW);
    
    // 触发超声波后，等待 ECHO 引脚变为高电平
    //Serial.printf("等待 ECHO 引脚变为高电平\n");
    double delta_time = pulseIn(ECHO, HIGH); // 检测高电平持续时间，注意返回值是微秒 us 
    float detect_distance = delta_time * 0.0343 / 2; // 计算距离单位 cm, 声速0.0343 cm / us
    Serial.printf("distance=%f cm\n", detect_distance); // 打印距离
    delay(500);
}