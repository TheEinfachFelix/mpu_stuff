#include "main.hpp"

float Gravitation = 9.80665;
float cal = .000061;
Vector out;
String x1 = "";
int flightGate = 1500;
uint32_t StringLength = 7300; //6987 fine 6987 not fine
const uint32_t MaxLaunchTime = 100000;

void setup() {
    Serial.begin(115200);
    wifiSetup();
    setupGyro();
}
void loop() {
    webSocket.loop();
    out = getGyro();
    float outx = out.ax * cal * Gravitation - out.gx;
    float outy = out.ay * cal * Gravitation - out.gy;
    float outz = out.az * cal * Gravitation - out.gz;
      
    if((outx+outy+outz)/3>flightGate){
        x1 = x1 + String(outx)+"\t"+String(outy)+"\t"+String(outz) +"\t" + millis() +"\n";
    }
    //Serial.println(String(x));
    //Serial.println(WiFi.localIP());
    //Serial.println(String(out.ax * cal * Gravitation - out.gx)+" "+ String(out.ay * cal * Gravitation - out.gy) + " " + String(out.az * cal * Gravitation - out.gz));
    delay(5);
}