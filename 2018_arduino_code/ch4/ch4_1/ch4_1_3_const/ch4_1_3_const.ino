#define LED 3
const int BUTTON = 2;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop() {
  if (digitalRead(BUTTON) == HIGH) {
    Serial.print(true);
    Serial.print(HIGH);
    Serial.println(OUTPUT);
    digitalWrite(LED, HIGH);
  } else {
    Serial.print(false);
    Serial.print(LOW);
    Serial.println(INPUT);
    digitalWrite(LED, LOW);
  }
}

