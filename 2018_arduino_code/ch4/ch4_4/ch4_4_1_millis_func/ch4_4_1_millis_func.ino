unsigned long past = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (myTimer(1000)) {
    Serial.println("1초마다 실행됩니다.");
  }
}

boolean myTimer(int waitTime) {
  unsigned long now = millis();
  if (now - past >= waitTime) {
    past = now;
    Serial.println(now / 1000);
    return true;
  }
  return false;
}

