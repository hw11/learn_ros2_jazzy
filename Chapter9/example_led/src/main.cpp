#include <Arduino.h>
void setup()
{
    pinMode(48, OUTPUT); // 设置 2 号引脚模式为 OUTPUT 模式
    Serial.begin(115200); // 设置串口波特率
}
void loop()
{
    Serial.printf("Turn on LED!\n");
    digitalWrite(48, LOW);  // 低电平，关闭 LED 灯
    delay(1000);            // 休眠 1000ms
    Serial.printf("Turn off LED!\n");
    digitalWrite(48, HIGH); // 高电平，打开 LED 灯
    delay(1000);            // 休眠 1000ms
}