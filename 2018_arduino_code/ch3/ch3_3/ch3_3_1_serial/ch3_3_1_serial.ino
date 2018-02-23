void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    Serial.write("Arduino : Hi, I'm Arduino");
    Serial.write('\n');

    Serial.write("you : ");
    Serial.write(Serial.read());
    Serial.write('\n');
  }
}

