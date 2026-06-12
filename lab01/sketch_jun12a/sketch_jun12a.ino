#define LED_PIN 2  // ESP32板载LED引脚

void setup() {
  Serial.begin(115200);  // 串口波特率
  pinMode(LED_PIN, OUTPUT);  // 设置LED引脚为输出模式
}

void loop() {
  Serial.println("Hello ESP32!");  // 串口输出
  digitalWrite(LED_PIN, HIGH);    // 点亮LED
  delay(1000);                    // 等待1秒
  digitalWrite(LED_PIN, LOW);     // 熄灭LED
  delay(1000);                    // 等待1秒
}