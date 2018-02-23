int value = 6;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(2) == HIGH){
    Serial.write("Hello!");
  } else if( value > 5){
    Serial.write("value가 5보다 큽니다.");
  }
}

