void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    Serial.write("Arduino : 원하는 말을 적어보세요");
    Serial.write('\n');
  }
}

