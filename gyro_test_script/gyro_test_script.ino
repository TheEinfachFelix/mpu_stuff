#include <Wire.h>
#include <math.h>
const int MPU = 0x68;
int16_t AcX, AcY, AcZ, Tmp, GyX, GyY, GyZ;
int AcXcal, AcYcal, AcZcal, GyXcal, GyYcal, GyZcal, tcal;
double t, tx, tf, pitch, roll;
void setup() {
Wire.begin();
Wire.beginTransmission(MPU);
Wire.write(0x6B);
Wire.write(0);
Wire.endTransmission(true);
Serial.begin(115200);
}
void loop() {
Wire.beginTransmission(MPU);
Wire.write(0x3B);
Wire.endTransmission(false);
Wire.requestFrom(MPU, 14, true);
AcXcal = -950;
AcYcal = 300;
AcZcal = 0;
tcal = -1600;
GyXcal = 480;
GyYcal = 170;
GyZcal = 210;
AcX = Wire.read() << 8 | Wire.read();
AcY = Wire.read() << 8 | Wire.read();
AcZ = Wire.read() << 8 | Wire.read();
Tmp = Wire.read() << 8 | Wire.read();
GyX = Wire.read() << 8 | Wire.read();
GyY = Wire.read() << 8 | Wire.read();
GyZ = Wire.read() << 8 | Wire.read();
tx = Tmp + tcal;
t = tx / 340 + 36.53;
tf = (t * 9 / 5) + 32;
getAngle(AcX, AcY, AcZ);

//Serial.print("Accelerometer: ");
Serial.print("");
Serial.print((AcX + AcXcal));//x
Serial.print(" ");
Serial.print((AcY + AcYcal));//y
Serial.print(" ");
Serial.println((AcZ + AcZcal));//Z

delay(5);
}
void getAngle(int Ax, int Ay, int Az) {
double x = Ax;
double y = Ay;
double z = Az;
pitch = atan(x / sqrt((y * y) + (z * z)));
roll = atan(y / sqrt((x * x) + (z * z)));
pitch = pitch * (180.0 / 3.14);
roll = roll * (180.0 / 3.14) ;
}
