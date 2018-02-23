unsigned long past = 0;
unsigned long waitTime = 0;
String waitTimeStr = "0";
boolean SW = false;

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  changeSW();
  int val = analogRead(A0);
  if (SW) {
    digitalWrite(3, HIGH);
    if (myTimer()) {
      SW = false;
      analogWrite(5, 0);
    } else {
      analogWrite(5, val / 10);
    }
  } else {
    digitalWrite(3, LOW);
    analogWrite(5, 0);
  }
}

void changeSW() {
  if (digitalRead(2) == HIGH) {
    SW = !SW;
    while (digitalRead(2) == HIGH) {
      Serial.println("버튼이 떨어지길 기다리는 중");
    }
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
  Serial.println((now-past)/1000);
  if (now - past >= waitTime && waitTime != 0) {
    past = now;
    waitTime = 0;
    waitTimeStr = "0";
    return true;
  }
  return false;

}
