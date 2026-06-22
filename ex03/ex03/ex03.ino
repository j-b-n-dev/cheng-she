// 验证SOS完整时序，三短三长三短循环正常
const int ledPin = 2;
const unsigned short tShortOn = 200;
const unsigned short tLongOn = 600;
const unsigned short tGap = 200;
const unsigned short tEndPause = 2000;

unsigned long preTime = 0;
int state = 0;
bool ledState = LOW;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  unsigned long cur = millis();
  if (cur - preTime < tGap) return;

  switch(state) {
    // S：3次短闪
    case 0: case 1: case 2:
      ledState = HIGH;
      digitalWrite(ledPin, ledState);
      preTime = cur + tShortOn;
      state++;
      break;
    case 3:
      ledState = LOW;
      digitalWrite(ledPin, ledState);
      preTime = cur;
      state = 4;
      break;
    // O：3次长闪
    case 4: case 5: case 6:
      ledState = HIGH;
      digitalWrite(ledPin, ledState);
      preTime = cur + tLongOn;
      state++;
      break;
    case 7:
      ledState = LOW;
      digitalWrite(ledPin, ledState);
      preTime = cur;
      state = 8;
      break;
    // S：3次短闪
    case 8: case 9: case 10:
      ledState = HIGH;
      digitalWrite(ledPin, ledState);
      preTime = cur + tShortOn;
      state++;
      break;
    case 11:
      ledState = LOW;
      digitalWrite(ledPin, ledState);
      preTime = cur;
      state = 12;
      break;
    // 一轮结束长时间停顿，重置循环
    case 12:
      preTime = cur + tEndPause;
      state = 0;
      break;
  }
}