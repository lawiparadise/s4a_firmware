void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    char data = Serial.read();
    
    if (data == 97) digitalWrite(3, HIGH);
    else digitalWrite(3, LOW);
    
    int data2 = data;

    Serial.println(data2);
    Serial.write(data2);
    Serial.println();
  }
}

