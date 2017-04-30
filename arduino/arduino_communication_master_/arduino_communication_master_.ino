//arduino communication (master)
#include <Wire.h>

void setup() {
  Wire.begin();
}

byte x = 0;

void loop() {
  Wire.beginTransmission(1); // send data with address (1): address 1 is slave address.
 // Wire.write("x is ");
  Wire.write(x);
  Wire.endTransmission();
  
  x++;
  delay(500);
}
