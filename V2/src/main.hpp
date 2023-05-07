#pragma once

// mpu libs
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
//general libs
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <math.h> 

#include "gyro.hpp"
#include "wifi.hpp"

extern Vector out;
extern WebSocketsServer webSocket;
extern sensors_event_t a, g, temp;
Adafruit_MPU6050 mpu;
