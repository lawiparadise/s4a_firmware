void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char temp = Serial.read();
    
    Serial.print("println1 : ");
    Serial.println(49); // 여기서 49는 4랑, 9를 각각 문자로('4', '9')보고 아스키코드값 52, 57을 전송한다. 이후 컴퓨터에선 이를 다시 4랑 9로 해석한다.
    Serial.print("write1 : ");
    Serial.write(49); // 49를 그냥 아스키 코드로 보낸다. 컴퓨터에선 이를 49로 보고 1로 해석한다.
    Serial.write('\n');

    int b = 49;
    Serial.print("println2 : ");
    Serial.println(b);
    Serial.print("write2 : ");
    Serial.write(b);
    Serial.write('\n');
  }
}
//위 아래 같은 결과 나옴.
