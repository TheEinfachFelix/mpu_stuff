#pragma once

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>



void wifiSetup();

extern const char* ssid;
extern const char* password;
extern AsyncWebServer server;
extern String x1;
extern String x2;
extern String x3;
extern bool flightState;