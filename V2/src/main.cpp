#include "main.hpp"

float Gravitation = 9.80665;
Vector out;
String x1, x2, x3 = "";
uint32_t StringLength = 9000; //6987 fine 6987 not fine 8000
bool full = 0;
double * AngleOut;
int32_t altimeter_ofset;
uint32_t Door_Time = 0;
uint32_t Door_Delay = 700;
bool Door_State; 

void setup() {
    Serial.begin(115200);
    pinMode(13, INPUT_PULLUP);
    pinMode(A0, INPUT);
    Landing_Gear.attach(16);
    

    wifiSetup();
    setupGyro();
    bmp_setup();
    
    altimeter_ofset = get_bpm_SealevelPressure();

    Landing_Gear.write(180);
}

void loop() {

    mpu.getEvent(&a, &g, &temp);
    webSocket.loop();
    out = getGyro();
    AngleOut = getAngle();
    if(x1.length() < StringLength){
        if(digitalRead(13) == 1 && !full){
            if(Door_Time == 0){
                Door_Time = int(millis());
            }
             if(millis() < (Door_Time + Door_Delay)){
                Landing_Gear.write(180);
                Door_State = 1;
    
            } else {
                Landing_Gear.write(0);
                Door_State = 0;
            }
            x1 = x1 + String((out.ax)) + "\t" + String((out.ay)) + "\t"+ String((out.az)) +"\t" + millis() 
            +"\t" + String(AngleOut[0]) +"\t" + String(AngleOut[1]) +"\t" + String(get_bpm_altitude(altimeter_ofset)) +"\t" + String(Door_State) + "\n";
            Serial.println(x1.length());
    } else {
        Door_Time = 0;
        Landing_Gear.write(180);
    }
    }

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

    Serial.println(WiFi.localIP());
    //Serial.println(String((out.ax)) + "\t" + String((out.ay)) + "\t"+ String((out.az)) +"\t" + millis() +"\t" + String(AngleOut[0]) +"\t" + String(AngleOut[1]) + String(get_bpm_SealevelPressure()));
    delay(15);
    

   
    //Serial.println(millis() > (Door_Time + Door_Delay));
}