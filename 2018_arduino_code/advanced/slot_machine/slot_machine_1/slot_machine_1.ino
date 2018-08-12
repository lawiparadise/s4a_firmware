int cnt = 0;
int num[4] = {0,};

void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(2, INPUT);
  randomSeed(analogRead(5));
}

void loop() {
  if (digitalRead(2) == HIGH) {
    while (digitalRead(2) == HIGH);
    cnt++;
    if (cnt > 3)cnt = 0;
    num[cnt] = random(1, 10);
    delay(50);
  }
  Serial.print(num[0]);
  Serial.print(num[1]);
  Serial.print(num[2]);
  Serial.println(num[3]);
}

