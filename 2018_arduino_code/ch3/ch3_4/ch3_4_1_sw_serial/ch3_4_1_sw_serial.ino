void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
}

void loop() {
  if(digitalRead(2) == HIGH){
    Serial.println("원하는 문구 적기");
  }
}

