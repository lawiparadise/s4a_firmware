int cnt = 0;

void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(2, INPUT);
  randomSeed(analogRead(5));
  delay(3000);
}

void loop() {
  int val = random(0, 1024);
  cnt = 0;

  Serial.println("Guess what number I think(0~1023)");
  Serial.println();

  while (1) {
    while (digitalRead(2) == LOW);
    int num = guessNumber();
    
    if (num > val) {
      Serial.println("down");
    } else if (num < val) {
      Serial.println("up");
    } else {
      Serial.println("You got it!!");
      Serial.print("Your count : ");
      Serial.println(cnt);
      Serial.println();
      delay(2000);
      break;
    }
    
  }
}

int guessNumber() {
  if (digitalRead(2) == HIGH) {
    while (digitalRead(2) == HIGH);
    cnt++;
    int temp = analogRead(0);
    Serial.println(temp);
    delay(50);
    return temp;
  }
}

