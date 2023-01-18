#include "main.hpp"

float Gravitation = 9.80665;
float cal = .000061;
Vector out;
String x1 = "";
String x2 = "";
String x3 = "";
int flightGate = 1500;
uint32_t StringLength = 8000; //6987 fine 6987 not fine
const uint32_t MaxLaunchTime = 1000;

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
    if(x1.length() < StringLength){
    if((outx+outy+outz)/3>flightGate){
        x1 = x1 + String(int(out.ax)) + "\t" + String(int(out.ay)) + "\t"+ String(int(out.az)) +"\t" + millis() 
        +"\t" + String(int(out.gx)) +"\t" + String(int(out.gy)) +"\t" + String(int(out.gz)) +"\n";
        Serial.println(x1.length());
    }}

    if(x1.length() > StringLength){ 
            Serial.print(x1.length());
    Serial.print(x2.length());
    Serial.println(x3.length());
        if(x2 == ""){
            x2 = x1;
            x1 = "";
        } else if (x2 != "" && x3 == ""){
            x3 = x2;
            x2 = "";
        }else{

        }
            Serial.print(x1.length());
    Serial.print(x2.length());
    Serial.println(x3.length());
    }


    Serial.println(WiFi.localIP());
    //Serial.println(String(out.ax * cal * Gravitation - out.gx)+" "+ String(out.ay * cal * Gravitation - out.gy) + " " + String(out.az * cal * Gravitation - out.gz));
    delay(5);
}