#pragma once

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <WebSocketsServer.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <Hash.h>

extern WebSocketsServer webSocket;

void wifiSetup();

extern const char* ssid;
extern const char* password;
extern String x1;
extern bool flightState;