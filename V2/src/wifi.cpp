#include "wifi.hpp"
#include "WIFIconfig.hpp"

extern const char* ssid;
extern const char* password;

ESP8266WiFiMulti WiFiMulti;
WebSocketsServer webSocket = WebSocketsServer(81);

void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length) {
    switch(type) {
        case WStype_DISCONNECTED:
            Serial.printf("[%u] Disconnected!\n", num);
            break;
        case WStype_CONNECTED: {
            IPAddress ip = webSocket.remoteIP(num);
            Serial.printf("[%u] Connected from %d.%d.%d.%d url: %s\n", num, ip[0], ip[1], ip[2], ip[3], payload);

            // send message to client
            webSocket.sendTXT(num, "Connected");
        }
            break;
        case WStype_TEXT:
            Serial.printf("[%u] get Text: %s\n", num, payload);
            if(payload[0] == 'c'){
                x1 = "";
                x2 = "";
                x3 = "";
                webSocket.sendTXT(num, "cleared");
            } else {
                webSocket.sendTXT(num, x3);
                webSocket.sendTXT(num, x2);
                webSocket.sendTXT(num, x1);
            }
            break;
        case WStype_BIN:
            break;
        case WStype_FRAGMENT_TEXT_START:
            break;
        case WStype_FRAGMENT_BIN_START:
            break;
        case WStype_FRAGMENT:
            break;
        case WStype_FRAGMENT_FIN:
            break;
        case WStype_PING:
            break;
        case WStype_PONG:
            break;
        case WStype_ERROR:
           break;
    }}

void wifiSetup(){
    //Serial.setDebugOutput(true);
    WiFiMulti.addAP(ssid, password);

    while(WiFiMulti.run() != WL_CONNECTED) {
        delay(100);
    }
    // start webSocket server
    webSocket.begin();
    webSocket.onEvent(webSocketEvent);
}