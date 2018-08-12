String fruits[8] = {"apple", "tomato", "strawberry", "pepper", 
"orange", "lemon", "banana", "cucumber"};

void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  delay(3000);
}

void loop() {
  Serial.println("think about your fruits and vegetables, Don't talk!!");
  Serial.println("apple, tomato, strawberry, pepper, orange, lemon, banana, cucumber");
  Serial.println();

  Serial.println("Is it red? answer y or n");
  if (getAnswer() == 'y') {
    Serial.println("Is it circle? answer y or n");
    if (getAnswer() == 'y') {
      Serial.println("Is it sweet? answer y or n");
      if (getAnswer() == 'y') {
        Serial.print("I got it! It is ");
        Serial.println(fruits[0]);
      } else {
        Serial.print("I got it! It is ");
        Serial.println(fruits[1]);
      }
    } else {
      Serial.println("Is it sweet? answer y or n");
      if (getAnswer() == 'y') {
        Serial.print("I got it! It is ");
        Serial.println(fruits[2]);
      } else {
        Serial.print("I got it! It is ");
        Serial.println(fruits[3]);
      }
    }
  } 
  else {
    Serial.println("Is it circle? answer y or n");
    if (getAnswer() == 'y') {
      Serial.println("Is it sweet? answer y or n");
      if (getAnswer() == 'y') {
        Serial.print("I got it! It is ");
        Serial.println(fruits[4]);
      } else {
        Serial.print("I got it! It is ");
        Serial.println(fruits[5]);
      }
    } else {
      Serial.println("Is it sweet? answer y or n");
      if (getAnswer() == 'y') {
        Serial.print("I got it! It is ");
        Serial.println(fruits[6]);
      } else {
        Serial.print("I got it! It is ");
        Serial.println(fruits[7]);
      }
    }
  }

  delay(2000);
  Serial.println("press any key");
  Serial.println();
  getAnswer();
}

char getAnswer() {
  while (!Serial.available());
  if (Serial.available()) {
    char input = Serial.read();
    return input;
  }
  return 0;
}

