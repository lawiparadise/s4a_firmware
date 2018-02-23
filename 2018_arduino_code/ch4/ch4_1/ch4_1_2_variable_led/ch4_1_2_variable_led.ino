void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(2, INPUT);
}

void loop() {
  int val = analogRead(A0);
  Serial.println(val);
  analogWrite(3, val / 5);
}

