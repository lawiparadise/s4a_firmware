boolean SW = false;
unsigned long past = 0;
unsigned long waitTime = 0;

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  changeSW();
  if (SW) {
    if (myTimer()) {
      SW = false;
    } else {
      digitalWrite(3, HIGH);
      analogWrite(5, analogRead(A0) / 100);
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
      Serial.println("버튼이 떨어지길 기다리는중");
    }
  }
}

boolean myTimer() {
  unsigned long now = millis();

  if (Serial.available()) {
    char c = Serial.read();
    past = now;
    waitTime = c - '0';
  }

  int myTime = (now - past) / 1000;
  Serial.println(myTime);

  if (myTime >= waitTime && waitTime != 0) {
    past = now;
    waitTime = 0;
    return true;
  }
  return false;
}

