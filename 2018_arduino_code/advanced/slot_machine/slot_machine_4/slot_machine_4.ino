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
  } else if ((num[1] == 7 || num[2] == 7 || num[3] == 7) && cnt == 3) {
    Serial.println("!!!!! rucky !!!!!");
    digitalWrite(3, HIGH);
  } else if (num[1] == 1 && num[2] == 1 && num[3] == 2 && cnt == 3) {
    Serial.println("!!!!! police !!!!!");
    digitalWrite(3, HIGH); delay(100);
    digitalWrite(3, LOW); delay(100);
  }
}

int rotto_count = 0;
void saveNumber() {
  if (digitalRead(2) == HIGH) {
    while (digitalRead(2) == HIGH);
    cnt++;
    if (cnt > 3)cnt = 0;
    num[cnt] = random(1, 10);

    if (cnt == 0)rotto_count++;
    if (rotto_count > 3 && cnt != 0) {
      num[cnt] = 7;
      if (cnt == 3)rotto_count = 0;
    }

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

