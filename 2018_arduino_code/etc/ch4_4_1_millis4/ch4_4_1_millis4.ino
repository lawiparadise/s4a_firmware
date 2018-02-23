unsigned long past = 0;
unsigned long waitTime = 0;
String waitTimeStr = "0";

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (myTimer()) {
    Serial.println("입력한 시간이 지난 뒤 실행되는 문장");
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
//    waitTime = 0;
    waitTimeStr = "0";
    return true;
  }
  return false;

}
