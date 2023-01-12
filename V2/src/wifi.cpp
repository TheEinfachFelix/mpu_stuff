#include "wifi.hpp"
#include "WIFIconfig.hpp"

extern const char* ssid;
extern const char* password;

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
        request->send(200, "text/plain", "Daten: " + String(millis()) + "\n" + String(x1)+String(x2)+String(x3));
    });

    server.onNotFound(notFound);
    server.begin();
}