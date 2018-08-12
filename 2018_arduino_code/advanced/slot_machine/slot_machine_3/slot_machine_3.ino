int cnt = 0;
int num[4] = {0,};

void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(2, INPUT);
  randomSeed(analogRead(5));
}

void loop() {
  saveNumber();
  printNumber();
  if (num[1] == 7 && num[2] == 7 && num[3] == 7 && cnt == 3) {
    Serial.println("!!!!! JACKPOT !!!!!");
    digitalWrite(3, HIGH);
  }
}

void saveNumber() {
  if (digitalRead(2) == HIGH) {
    while (digitalRead(2) == HIGH);
    cnt++;
    if (cnt > 3)cnt = 0;
    num[cnt] = random(1, 10);
    delay(50);
  }
}

void printNumber() {
  if (cnt == 0) {
    Serial.print(random(10));
    Serial.print(random(10));
    Serial.print(random(10));
  } else if (cnt == 1) {
    Serial.print(num[1]);
    Serial.print(random(10));
    Serial.print(random(10));
  } else if (cnt == 2) {
    Serial.print(num[1]);
    Serial.print(num[2]);
    Serial.print(random(10));
  } else if (cnt == 3) {
    Serial.print(num[1]);
    Serial.print(num[2]);
    Serial.print(num[3]);
  }
  Serial.println();
}

