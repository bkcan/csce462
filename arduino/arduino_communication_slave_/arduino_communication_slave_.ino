//arduino communication (slave)
#include <Wire.h>

void setup() {
  Wire.begin(1); // to set address of slave
  Wire.onReceive(receiveEvent); 
  Serial.begin(9600);
}
   
void loop() {
  delay(1000);
}

void receiveEvent(int parameter) { 
  /*while(1 < Wire.available()) { 
    char c = Wire.read();
    Serial.print(c);
  }*/
while(Wire.available() > 0){
  int x = Wire.read();
  Serial.println(x);
}
}

