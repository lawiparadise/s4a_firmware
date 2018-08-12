int height = 0;

void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(2, INPUT);
  delay(3000);
}

void loop() {
  Serial.println("insert height of tree");
  height = getNumber() - '0';
  Serial.println(height);

  for (int i = 0; i < height; i++) {
    for (int k = 0; k < i + 1; k++) {
      Serial.print("*");
    }
    Serial.println();
  }
  
  Serial.println();
}

char getNumber() {
  while (!Serial.available());
  if (Serial.available()) {
    char input = Serial.read();
    return input;
  }
  return 0;
}

