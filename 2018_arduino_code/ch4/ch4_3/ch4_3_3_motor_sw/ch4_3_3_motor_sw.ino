int cnt = 0;

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  int val = getCnt();
  analogWrite(5, val * 30);
}

int getCnt() {
  if (digitalRead(2) == HIGH) {
    cnt++;
    if (cnt > 3) cnt = 0;
    while (digitalRead(2) == HIGH) {
      Serial.println("버튼이 떨어지길 기다리는 중");
    }
    Serial.print("버튼 눌림 횟수 : ");
    Serial.println(cnt);
  }
  return cnt;
}

