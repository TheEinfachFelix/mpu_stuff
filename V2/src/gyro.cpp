#include "gyro.hpp"

const int MPU = 0x68;
int16_t AcX, AcY, AcZ, Tmp, GyX, GyY, GyZ;
int AcXcal, AcYcal, AcZcal, GyXcal, GyYcal, GyZcal, tcal;
double t, tx, tf, pitch, roll;
Vector ra;

void setupGyro(){
    if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  mpu.setAccelerometerRange(MPU6050_RANGE_16_G);
  Serial.print("Accelerometer range set to: ");
  switch (mpu.getAccelerometerRange()) {
  case MPU6050_RANGE_2_G:
    Serial.println("+-2G");
    break;
  case MPU6050_RANGE_4_G:
    Serial.println("+-4G");
    break;
  case MPU6050_RANGE_8_G:
    Serial.println("+-8G");
    break;
  case MPU6050_RANGE_16_G:
    Serial.println("+-16G");
    break;
  }
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  Serial.print("Gyro range set to: ");
  switch (mpu.getGyroRange()) {
  case MPU6050_RANGE_250_DEG:
    Serial.println("+- 250 deg/s");
    break;
  case MPU6050_RANGE_500_DEG:
    Serial.println("+- 500 deg/s");
    break;
  case MPU6050_RANGE_1000_DEG:
    Serial.println("+- 1000 deg/s");
    break;
  case MPU6050_RANGE_2000_DEG:
    Serial.println("+- 2000 deg/s");
    break;
  }

  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
  Serial.print("Filter bandwidth set to: ");
  switch (mpu.getFilterBandwidth()) {
  case MPU6050_BAND_260_HZ:
    Serial.println("260 Hz");
    break;
  case MPU6050_BAND_184_HZ:
    Serial.println("184 Hz");
    break;
  case MPU6050_BAND_94_HZ:
    Serial.println("94 Hz");
    break;
  case MPU6050_BAND_44_HZ:
    Serial.println("44 Hz");
    break;
  case MPU6050_BAND_21_HZ:
    Serial.println("21 Hz");
    break;
  case MPU6050_BAND_10_HZ:
    Serial.println("10 Hz");
    break;
  case MPU6050_BAND_5_HZ:
    Serial.println("5 Hz");
    break;
  }
    delay(100);
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

Vector getGyro(){
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);

    AcXcal = -950;
    AcYcal = 300;
    AcZcal = 0;
    tcal = -1600;
    GyXcal = 600;
    GyYcal = -85;
    GyZcal = -180;
    //Serial.print(a.acceleration.x);
    getAngle(a.acceleration.x, a.acceleration.y, a.acceleration.z);
    ra.ax = (a.acceleration.x + AcXcal);
    ra.ay = (a.acceleration.y + AcYcal);
    ra.az = (a.acceleration.z + AcZcal);
    ra.gx = (g.gyro.x + GyXcal);
    ra.gy = (g.gyro.y + GyYcal);
    ra.gz = (g.gyro.z + GyZcal);
    return ra;
}