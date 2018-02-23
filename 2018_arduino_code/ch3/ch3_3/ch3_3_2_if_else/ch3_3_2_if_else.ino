int value = 6;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(2) == HIGH){
    Serial.write("Hello!");
  } else{
    Serial.write("그 외의 경우 실행됩니다.");
  }
}

