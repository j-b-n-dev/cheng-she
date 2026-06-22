const int ledPin = 2;
unsigned long preTime = 0;
const long interval = 500;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  unsigned long curTime = millis();
  if (curTime - preTime >= interval) {
    preTime = curTime;
    digitalWrite(ledPin, !digitalRead(ledPin));
    Serial.print("运行毫秒：");
    Serial.println(curTime);
  }
}