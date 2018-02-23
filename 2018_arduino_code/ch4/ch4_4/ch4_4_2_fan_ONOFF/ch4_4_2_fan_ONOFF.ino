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
    digitalWrite(3, HIGH);
  } else {
    digitalWrite(3, LOW);
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

