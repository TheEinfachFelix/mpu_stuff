#include "main.hpp"

float Gravitation = 9.80665;
Vector out;
String x1, x2, x3 = "";
uint32_t StringLength = 9000; //6987 fine 6987 not fine 8000
bool full = 0;
double * AngleOut;
int32_t altimeter_ofset;

void setup() {
    Serial.begin(115200);
    pinMode(13, INPUT_PULLUP);
    pinMode(A0, INPUT);
    Landing_Gear.attach(16);
    

    wifiSetup();
    setupGyro();
    bmp_setup();
    
    altimeter_ofset = get_bpm_SealevelPressure();
}

void loop() {

    mpu.getEvent(&a, &g, &temp);
    webSocket.loop();
    out = getGyro();
    AngleOut = getAngle();
    if(x1.length() < StringLength){
        if(digitalRead(13) == 1 && !full){
            x1 = x1 + String((out.ax)) + "\t" + String((out.ay)) + "\t"+ String((out.az)) +"\t" + millis() 
            +"\t" + String(AngleOut[0]) +"\t" + String(AngleOut[1]) +"\t" + String(get_bpm_altitude(altimeter_ofset)) + "\n";
            Serial.println(x1.length());
    }}

    if(x1.length() >= StringLength){
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

    //Serial.println(WiFi.localIP());
    //Serial.println(String((out.ax)) + "\t" + String((out.ay)) + "\t"+ String((out.az)) +"\t" + millis() +"\t" + String(AngleOut[0]) +"\t" + String(AngleOut[1]) + String(get_bpm_SealevelPressure()));
    delay(15);
    Landing_Gear.write(0);

}