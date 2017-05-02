
/********************************************************
** Download from:                                      **
** http://www.alhin.de/arduino/index.php?n=44          **
********************************************************/

#include <AH_EasyDriver.h>

//AH_EasyDriver(int RES, int DIR, int STEP);
// RES -> RESOLUTION per full revolve
// DIR -> DIRECTION PIN
// STEP -> STEPPING PIN
AH_EasyDriver stepper(200,A3,A2);   // Initialisation
AH_EasyDriver stepper2(200,14,15);
AH_EasyDriver stepper3(200,10,16);


void setup() {
  Serial.begin(57600);         
//stepper.setSpeedHz(100);           // Hz, steps per second
}

void loop() {

  //The RPM of all the motors should be the same.
  stepper.setSpeedRPM(15);
  stepper.rotate(360);
  delay(3000);
  stepper2.rotate(-360);
  delay(3000);
  
  

  
}




void command(AH_EasyDriver unit, double rpm, double rot, int n){
  //modify to use timers later.
  for(int i = 0; i < n; i++){
    unit.setSpeedRPM(rpm);
  unit.rotate(rot);
  delay(500);
  }
}

void setallRPM(double rpm){
  stepper.setSpeedRPM(rpm);
  stepper2.setSpeedRPM(rpm);
  stepper3.setSpeedRPM(rpm);
}

void rotateAll(double rot, double rot2, double rot3, int n){
  for(int i = 0; i < n; i++){
    stepper.rotate(rot);
    stepper2.rotate(rot2);
    stepper3.rotate(rot3);
  }
  delay(1000);
}




