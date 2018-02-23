void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char a = Serial.read(); // 1넣으면 '1'이 들어온다. 이 값은 아스키코드로 49를 받은것과 같다. 즉 char a = '1';랑 같다.
    Serial.print("println1 : ");
    Serial.println(a); // 1이 출력된다. 왜지? char형을 println하면 걍 다 아스키로 보내는 듯하다.
    Serial.print("write1 : ");
    Serial.write(a); // 49를 그냥 아스키 코드로 보낸다. 컴퓨터에선 이를 49로 보고 1로 해석한다.
    Serial.write('\n');

    char b = 49; // char b = '1';과 같은 효과
    Serial.print("println2 : ");
    Serial.println(b);
    Serial.print("write2 : ");
    Serial.write(b);
    Serial.write('\n');
  }
}
//역시 같은 결과!!
