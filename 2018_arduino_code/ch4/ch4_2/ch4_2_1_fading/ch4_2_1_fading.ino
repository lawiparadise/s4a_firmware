void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);
}

void loop() {
  for (int i = 0; i <= 255 ; i += 5) {
    Serial.println(i);
    analogWrite(3, i);
    delay(30);
  }
  for (int i = 255; i >= 0 ; i -= 5) {
    Serial.println(i);
    analogWrite(3, i);
    delay(30);
  }
}

