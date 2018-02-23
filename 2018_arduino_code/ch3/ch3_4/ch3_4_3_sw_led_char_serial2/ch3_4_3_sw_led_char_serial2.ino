void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    int data = Serial.read();
    
    if(data == '1') digitalWrite(3, HIGH);
    else digitalWrite(3, LOW);
    
    Serial.print("println : ");
    Serial.println(data++);
    Serial.print("write : ");
    Serial.write(data);
    Serial.write('\n');
  }
}

