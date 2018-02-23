unsigned long past = 0;
unsigned long waitTime = 0;
String waitTimeStr = "0";
boolean SW = false;
int cnt = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int val = getCnt();
  if (SW) {
    SW = false;
    analogWrite(5, val * 30);
  } else {
    if (myTimer()) {
      Serial.println("시간 초과");
      cnt = 0;
      analogWrite(5, 0);
    }
  }
}

int getCnt() {
  if (digitalRead(2) == HIGH) {
    SW = true;
    cnt++;
    if (cnt > 3) cnt = 0;
    while (digitalRead(2) == HIGH) {
      Serial.println("버튼이 떨어지길 기다리는 중");
    }
    Serial.print("버튼 눌림 횟수 : ");
    Serial.println(cnt);
    return cnt;
  } else {
    return 0;
  }

}

boolean myTimer() {
  unsigned long now = millis();

  if (Serial.available()) {
    while (Serial.available()) {
      char c = Serial.read();
      waitTimeStr += c;
    }
    past = now;
    waitTime = waitTimeStr.toInt();
  }

  if (now - past >= waitTime && waitTime != 0) {
    past = now;
    waitTime = 0;
    waitTimeStr = "0";
    return true;
  }
  return false;

}
