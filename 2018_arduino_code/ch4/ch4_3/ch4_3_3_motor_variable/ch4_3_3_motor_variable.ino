void setup() {
  Serial.begin(9600);
  pinMode(5, OUTPUT);
}

void loop() {
  int val = analogRead(A0);
  Serial.println(val);
  analogWrite(5, val / 100);
}

