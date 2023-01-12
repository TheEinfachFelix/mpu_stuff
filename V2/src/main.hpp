#pragma once

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <math.h> 

#include "gyro.hpp"
#include "wifi.hpp"
//#include "config.hpp"

extern AsyncWebServer server;

extern String x1;
extern String x2;
extern String x3;
extern Vector out;
extern bool flightState;