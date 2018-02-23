void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    Serial.write("Arduino : I'm genius \n");
    int val = Serial.read();
    
    if (val == '0') {
      Serial.write("Arduino : you say ");
      Serial.write(val);
    } else if (val == '1') {
      Serial.write("Arduino : you say ");
      Serial.write(val);
    } else {
      Serial.write("Arduino : what? ");
    }
    
    Serial.write("\n");
  }
}

