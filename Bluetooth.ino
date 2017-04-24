#include <SoftwareSerial.h>
#include <string.h>
#define LED_PIN 2

SoftwareSerial mySerial(3, 2); // RX, TX  
// Connect HM10      Arduino Uno
//     Pin 1/TXD          Pin 3
//     Pin 2/RXD          Pin 2

void setup() {  
  Serial.begin(9600);
  // If the baudrate of the HM-10 module has been updated,
  // you may need to change 9600 by another value
  // Once you have found the correct baudrate,
  // you can update it using AT+BAUDx command 
  // e.g. AT+BAUD0 for 9600 bauds
  mySerial.begin(9600);
}

int array_size;
void loop() {  
  String c;
  if (mySerial.available()) {
    c = mySerial.readString();  
    //c = "up.right.left.";
    Serial.print("Original: ");
    Serial.println(c);
    String *s;
    s = parseCommand(c);
  }
}

String * parseCommand(String s){ //separates string whenever a period is read
    int periods = 0;
    for (int i = 0; i < s.length(); i++){ //checks every character in string
        if (s[i] == '.'){ //finds number of periods in string
          periods++;
        }  
    }
    
    array_size = periods;
    String myarray[periods]; //size of array is num of periods
    String temp = "";
    int index = 0;
    for (int i = 0; i < s.length(); i++){ 
        if (s[i] != '.'){
          temp += s[i];
        }
        if (s[i] == '.'){
          myarray[index] = temp;
          index++;
          temp = "";  
        }
    }
    Serial.println("Parsed Strings: "); //Separated commands are in this for loop
    for (int j = 0; j < array_size; j++){
        Serial.println(myarray[j]); //modify code here to use 
    }
    
    return myarray;
}

