#pragma once


#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <math.h> 

#include "gyro.hpp"
#include "wifi.hpp"

extern String x1;
extern String x2;
extern String x3;
extern Vector out;
extern WebSocketsServer webSocket;
Adafruit_MPU6050 mpu;