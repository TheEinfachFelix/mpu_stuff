#include "wifi.hpp"

const char* ssid = "PW5B";
const char* password = "51823423816189225268";

const char* PARAM_MESSAGE = "message";

void notFound(AsyncWebServerRequest *request) {
    request->send(404, "text/plain", "Not found :)");
}


void wifiSetup(){
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    if (WiFi.waitForConnectResult() != WL_CONNECTED) {
        Serial.printf("WiFi Failed!\n");
        return;
    }

    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());

    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(200, "text/plain", "Daten: " + String(millis()) + "\n" + String(x1));
    });

    server.onNotFound(notFound);
    server.begin();
}