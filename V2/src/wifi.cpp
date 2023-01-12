#include "wifi.hpp"

const char* ssid = "pw:1234";
const char* password = "14082005";

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
        request->send(200, "text/plain", "Daten: " + String(millis()) + "\n" + String(x1)+String(x3)+String(x2));
    });

    server.onNotFound(notFound);
    server.begin();
}