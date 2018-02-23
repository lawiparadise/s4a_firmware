char row1[6] = {' ', '/', ')', ' ', '/', ')'};
char row2[6] = {40, 45, 95, 45, 42, 41};
char row3[7] = "(>O< )";

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    Serial.read();
    for (int i = 0 ; i < 6 ; i++) {
      Serial.print(row1[i]);
    }
    Serial.print('\n');
    Serial.println(row2);
    Serial.println(row3);
  }                                    
}

