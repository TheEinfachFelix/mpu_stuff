#include "main.hpp"

float Gravitation = 9.80665;
float cal = .000061;
Vector out;
String x1 = "";
String x2 = "";
String x3 = "";
int flightGate = 420; //1500
uint32_t StringLength = 9000; //6987 fine 6987 not fine 8000
const uint32_t MaxLaunchTime = 1000;
bool full = 0;

void setup() {
    Serial.begin(115200);
    pinMode(13, INPUT_PULLUP);
    wifiSetup();
    setupGyro();
}
void loop() {
    webSocket.loop();
    out = getGyro();
    //float outx = out.ax * cal * Gravitation - out.gx;
    //float outy = out.ay * cal * Gravitation - out.gy;
    //float outz = out.az * cal * Gravitation - out.gz;
    if(x1.length() < StringLength){
    if(digitalRead(13) == 1 && !full){
        x1 = x1 + String((out.ax)) + "\t" + String((out.ay)) + "\t"+ String((out.az)) +"\t" + millis() 
        +"\t" + String((out.gx)) +"\t" + String((out.gy)) +"\t" + String((out.gz)) +"\n";
        Serial.println(x1.length());
        
    }}

    //Serial.println((abs(out.ax)+abs(out.ay)+abs(out.az))/3);
    //Serial.print(digitalRead(13));
    if(x1.length() > StringLength){
        full = 0;
        if(x2 == ""){
            x2 = x1;
            x1 = "";
        } else if (x2 != "" && x3 == ""){
            x3 = x2;
            x2 = "";
        }else{
            Serial.println("full");
            full = 1;
            Serial.println(x1.length());
        }
    }
    Serial.println(WiFi.localIP());
    //Serial.println(String(out.ax * cal * Gravitation - out.gx)+" "+ String(out.ay * cal * Gravitation - out.gy) + " " + String(out.az * cal * Gravitation - out.gz));
    delay(15);
}