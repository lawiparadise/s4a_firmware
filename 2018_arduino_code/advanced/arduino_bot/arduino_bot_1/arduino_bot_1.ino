


void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  delay(3000);
}

void loop() {
  Serial.println("input your number");

  while (!Serial.available());
  if (Serial.available()) {
    char input = Serial.read();
    Serial.println(input);
  }
  
}

