# mpu_stuff

## accel magic 
int x = (AcX + AcXcal);
int y = (AcY + AcYcal);
int z = (AcZ + AcZcal);
int gx = (GyX + GyXcal);
int gy = (GyY + GyYcal);
int gz = (GyZ + GyZcal);
Serial.print("");
Serial.print(x * .000061f * 9.80665f- gx);//x
Serial.print(" ");
Serial.print(y * .000061f * 9.80665f- gy);//y
Serial.print(" ");
Serial.println(z * .000061f * 9.80665f- gz);//Z

## better web stuff
https://www.w3schools.com/xml/ajax_intro.asp
https://github.com/me-no-dev/ESPAsyncWebServer#template-processing
https://github.com/Links2004/arduinoWebSockets/tree/master/examples

soket /netcat
websockte
=(A1*0,000061 * 9,80665) - E1
192.168.222.221
ws://192.168.178.84:81