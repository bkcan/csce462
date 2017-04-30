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

//example automatic command
//"cameraType:camera,filmType:timpelapse,startX:degrees,startY:degrees,startZ:degrees,endX:degrees,endY:degrees,endZ:degrees,"

int array_size;
String mode; //auto or manual

void loop() {  
  String c;
  if (mySerial.available()) {
    c = mySerial.readString();  
    //below are sample strings. One is manual and one is auto
    //c = "manual,up,right,left,"; 
    //c = "auto,cameraType:camera,filmType:timpelapse,startX:degrees,startY:12,startZ:0,endX:degrees,endY:80,endZ:15,";
    Serial.print("Original: ");
    Serial.println(c);
    String *s;
    s = parseCommand(c);
  }
}

String * parseCommand(String s){ //separates string whenever a comma is read
    int commas = 0;
    for (int i = 0; i < s.length(); i++){ //checks every character in string
        if (s[i] == ','){ //finds number of commas in string
          commas++;
        }  
    }
    
    array_size = commas;
    String myarray[commas]; //size of array is num of periods
    String temp = "";
    int index = 0;
    for (int i = 0; i < s.length(); i++){ 
        if (s[i] != ','){
          temp += s[i];
        }
        if (s[i] == ','){
          myarray[index] = temp;
          index++;
          temp = "";  
        }
    }
    mode = myarray[0];
    Serial.println("Parsed Strings: "); //Separated commands are in this for loop
    for (int j = 1; j < array_size; j++){
        Serial.println(myarray[j]); //modify code here to use
        if (mode == "auto"){ //If mode is auto, separate keys and values
            SeparateKey(myarray[j]); //in this case each myarray[j] will be a string in this form key:value. A key and value separated by colon 
        }
        
    }
    
    return myarray;
}

void SeparateKey(String s){ //separates the key:value string into 2 strings. 1 for key and 1 for value
    String key = "";
    String value = "";
    bool endofkey = false;
    int index = 0;
    for (int i = 0; i < s.length(); i++){ 
        if (s[i] != ':' && !endofkey){
          key += s[i];
        }
        if (s[i] == ':'){
          endofkey = true;  
        }
        if (s[i] != ':' && endofkey){
          value += s[i];
        }
    }
    Serial.print("Key: ");
    Serial.println(key);
    Serial.print("Value: ");
    Serial.println(value);
    //maybe add a few lines so that the values become ints/doubles instead of strings
    if (key == "startX" || key == "endX" || key == "startY" || key == "endY" || key == "startZ" || key == "endZ"){
        const char *mychar = value.c_str();
        double dVal = atof(mychar);
        Serial.println(dVal);
    }
    
}


//maybe make ints into doubles
void automaticMode(int xStart, int xEnd, int yStart, int yEnd, int zStart, int zEnd, String mode, float totaltime, float shutterspeed){
    
}


