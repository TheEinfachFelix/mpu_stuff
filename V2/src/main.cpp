#include "main.hpp"


AsyncWebServer server(80);

float Gravitation = 9.80665;
float cal = .000061;
Vector out;
String x1;
String x2;
String x3;
bool flightState = false;
int flightGate = 1500;
int o =0;
int StringLength = 11400;

void setup() {
    Serial.begin(115200);
    wifiSetup();
    setupGyro();
}
void loop() {
    out = getGyro();
    float outx = out.ax * cal * Gravitation - out.gx;
    float outy = out.ay * cal * Gravitation - out.gy;
    float outz = out.az * cal * Gravitation - out.gz;
    if ((outx+outy+outz)/3>flightGate){
        flightState = true;
        if(!flightState){
            //flightState = false;
        } else{
            flightState = true;
        }        
    } 
    if(flightState){
        //x1 = x1 + String(outx)+"\t"+String(outy)+"\t"+String(outz) + "\n";
        Serial.println("x");
        if (x1.length() < StringLength){
            Serial.println("x1");
            x1 = x1 + String(outx)+"\t"+String(outy)+"\t"+String(outz) + "\n";
        }else if (x2.length() < StringLength)
        {
            Serial.println("x2");
            x2 = x2 + String(outx)+"\t"+String(outy)+"\t"+String(outz) + "\n";
        }else if (x3.length() >! StringLength)
        {
            Serial.println("x3");
            x3 = x3 + String(outx)+"\t"+String(outy)+"\t"+String(outz) + "\n";
        }else if (x3.length() > StringLength)
        {
            Serial.println("xxxx");
            x1 ="r";
            x2 ="";
            x3 ="";
        }

        
    }
    
    if (o<x1.length()){
        o= x1.length();
    }
    Serial.println(x1.length());
    //Serial.println(String(out.ax * cal * Gravitation - out.gx)+" "+ String(out.ay * cal * Gravitation - out.gy) + " " + String(out.az * cal * Gravitation - out.gz));
    delay(5);
}