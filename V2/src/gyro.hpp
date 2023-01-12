#pragma once

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