
/********************************************************
** Download from:                                      **
** http://www.alhin.de/arduino/index.php?n=44          **
********************************************************/

#include <AH_EasyDriver.h>

//AH_EasyDriver(int RES, int DIR, int STEP);
// RES -> RESOLUTION per full revolve
// DIR -> DIRECTION PIN
// STEP -> STEPPING PIN
AH_EasyDriver stepper(200,A1,A2);   // Initialisation

void setup() {
//  Serial.begin(57600);         // RPM , rotations per minute
//stepper.setSpeedHz(100);           // Hz, steps per second
}

void loop() {
  
  stepper.setSpeedRPM(50);
  stepper.rotate(720.0);            // rotate 720° at diff speeds
  delay(1000);
  stepper.setSpeedRPM(100);
  stepper.rotate(720.0);           
  delay(1000);
  stepper.setSpeedRPM(400);
  stepper.rotate(-720.0);            
  delay(1000);
  
  
}


