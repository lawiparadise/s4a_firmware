void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    int a = Serial.read(); // 1넣으면 '1'이 들어온다. 이 값은 아스키코드로 49를 받은것과 같다. 즉 int a = 49;랑 같다.
    
    Serial.print("println1 : ");
    Serial.println(a); // 여기서 49는 4랑, 9를 각각 문자로('4', '9')보고 아스키코드값 52, 57을 전송한다. 이후 컴퓨터에선 이를 다시 4랑 9로 해석한다.
    Serial.print("write1 : ");
    Serial.write(a); // 49를 그냥 아스키 코드로 보낸다. 컴퓨터에선 이를 49로 보고 1로 해석한다.
    Serial.write('\n');

    int b = 49;
    Serial.print("println2 : ");
    Serial.println(b);
    Serial.print("write2 : ");
    Serial.write(b);
    Serial.write('\n');
  }
}
//시리얼을 통해서는 한 바이트 단위로 해석을 하게 되고, 아스키코드값으로 온걸로 알고 그걸 문자로 바꿔서 보여준다.
