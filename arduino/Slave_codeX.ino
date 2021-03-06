#include <Wire.h>

void setup() {
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
}

void loop() {
  delay(100);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
  String command = "";
  while (0 < Wire.available()) { // loop through all chars
    char c = Wire.read(); // receive byte as a character
    command += c;
  }
  Serial.println(command);         // print the command
  //if (command == "left") { rotateStepper1(-90);}
  //if (command == "right") { rotateStepper1(90);}
}
