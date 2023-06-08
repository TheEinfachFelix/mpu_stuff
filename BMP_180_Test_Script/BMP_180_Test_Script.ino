#include <Adafruit_BMP085.h>
Adafruit_BMP085 bmp;
void setup() {
Serial.begin(9600);
if (!bmp.begin()) {
Serial.println("Could not find a valid BMP085 sensor,check wiring!");
while (1) {}
}
}
void loop() {

Serial.print("Pressure at sealevel (calculated) = ");
Serial.print(bmp.readSealevelPressure());
Serial.println(" Pa");
// you can get a more precise measurement of altitude
// if you know the current sea level pressure which will
// vary with weather and such. If it is 1015 millibars
// that is equal to 101500 Pascals.
Serial.print("Real altitude = ");
Serial.print(bmp.readAltitude(99524));
Serial.println(" meters");
Serial.println();
delay(500);
}
