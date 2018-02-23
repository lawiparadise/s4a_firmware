void setup() {
  Serial.begin(9600);
}

void loop() {
  int val = analogRead(A0);
  
  if (val > 614) {
    Serial.println("Arduino : I think HIGH");
  } else if (val < 614 && val > 307) {
    Serial.println("Arduino : I don't know");
  } else if (val < 307) {
    Serial.println("Arduino : I think LOW");
  }
  
//  Serial.println(val);
  delay(500);
}

