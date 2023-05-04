#pragma once


#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <Wire.h>
#include <math.h>
#include <Arduino.h>

struct Vector
{
    float ax;
    float ay;
    float az;
    float gx;
    float gy;
    float gz;
};

void setupGyro();
Vector getGyro();
void getAngle(int Ax, int Ay, int Az);

extern Adafruit_MPU6050 mpu;