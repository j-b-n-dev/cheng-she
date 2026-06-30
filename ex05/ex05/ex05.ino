// ex05 多档位触摸调速呼吸灯（新版适配）
const int LED_PIN = 2;
#define TOUCH_PIN T0
const int touchThresh = 30;

int speedGear = 1;
unsigned int delayList[] = {50, 20, 8};
int brightness = 0;
int step = 1;
int lastTouchState = 0;
unsigned long debounceTime = 0;
const unsigned long debounceMs = 50;

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  // 新版替代 ledcSetup(0,5000,8)+ledcAttachPin(LED_PIN,0)
  ledcAttach(LED_PIN, 5000, 8);
  ledcWrite(LED_PIN, 0);
}

void loop() {
  int touchVal = touchRead(TOUCH_PIN);
  int currTouchState = (touchVal < touchThresh) ? 1 : 0;

  if ((millis() - debounceTime) > debounceMs) {
    if (currTouchState == 1 && lastTouchState == 0) {
      speedGear = speedGear >=3 ? 1 : speedGear+1;
      Serial.print("切换至档位：");
      Serial.println(speedGear);
      debounceTime = millis();
    }
    lastTouchState = currTouchState;
  }

  brightness += step;
  if(brightness <=0 || brightness >=255) step = -step;
  ledcWrite(LED_PIN, brightness);
  delay(delayList[speedGear-1]);
}