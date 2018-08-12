#include<Wire.h>
#include<Mouse.h>

const int MPU_ADDRESS = 0x68;
int16_t AcX, AcY, AcZ, Tmp, GyX, GyY, GyZ;

void setup() {
  Wire.begin();
  Wire.beginTransmission(MPU_ADDRESS);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
  Serial.begin(115200);
  pinMode(5, OUTPUT);

  Mouse.begin();
}

void loop() {
  Wire.beginTransmission(MPU_ADDRESS);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_ADDRESS, 14, true);

  AcX = Wire.read() << 8 | Wire.read();
  AcY = Wire.read() << 8 | Wire.read();
  AcZ = Wire.read() << 8 | Wire.read();
  Tmp = Wire.read() << 8 | Wire.read();
  GyX = Wire.read() << 8 | Wire.read();
  GyY = Wire.read() << 8 | Wire.read();
  GyZ = Wire.read() << 8 | Wire.read();

  Serial.print("AcX = "); Serial.println(AcX);
  //  Serial.print("AcY = "); Serial.println(AcY);
  //  Serial.print("AcZ = "); Serial.println(AcZ);
  //  Serial.print("Tmp = "); Serial.println(Tmp / 340.00 + 36.53);
  //  Serial.print("GyX = "); Serial.println(GyX);
  //  Serial.print("GyY = "); Serial.println(GyY);
  //  Serial.print("GyZ = "); Serial.println(GyZ);

  if (AcX < -8000){
    Mouse.move(5,0,0);
  } else if(AcX > 8000){
    Mouse.move(-5,0,0);
  }
}

