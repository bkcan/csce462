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
//"auto,cameraType:camera,filmType:timpelapse,startX:degrees,startY:degrees,startZ:degrees,endX:degrees,endY:degrees,endZ:degrees,"

int array_size;
String mode; //auto or manual

void loop() {  
  String c;
  if (mySerial.available()) {
    c = mySerial.readString();  
    //below are sample strings. One is manual and one is auto
    //c = "manual,up,manual,right,manual,left,manual,photo,"; 
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
    String myarray[commas]; //size of array is number of commas
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
    mode = myarray[0]; //the first string found should be "auto" or "manual" so it knows what mode
    Serial.println("Parsed Strings: "); //Separated strings are in this for loop
    for (int j = 1; j < array_size; j++){ //j starts at 1 because 0 index is the mode
        if (mode == "manual" && j%2 != 0){ //if manual mode, then commands only have odd index because every other string is "manual"
          //here is where the manual commands can be accessed
          //myarray[j] will be a manual command so up, left, down, right, photo
          //Up to yall to decide what each manual command will do
          //if(myarray[j] == "left") { rotateStepper1(-90);}
          //if(myarray[j] == "right") { rotateStepper1(90);}
          //if(myarray[j] == "up") { rotateStepper2(45);}
          //if(myarray[j] == "down") { rotateStepper2(-45);}
          //if(myarray[j] == "photo") { takePicture();}
          Serial.println(myarray[j]); //modify code here to use
        }
        
        if (mode == "auto"){ //If mode is auto, separate keys and values
            Serial.println(myarray[j]);
            SeparateKey(myarray[j]); //in this case each myarray[j] will be a string in this form key:value. A key and value separated by colon 
        }
        
    }
    //once automaticMode function is worked on, it should be called here
    //automaticMode(all the variables that need to be input)
    return myarray;
}


//separates the key:value string into 2 strings. 1 for key and 1 for value
//Also converts the values from strings to doubles if that's necessary
void SeparateKey(String s){ 
    String key = "";
    String value = "";
    bool endofkey = false;
    int index = 0;
    for (int i = 0; i < s.length(); i++){ 
        if (s[i] != ':' && !endofkey){ //if the char is not a colon and no colon found, add char to key string
          key += s[i];
        }
        if (s[i] == ':'){ ////if the char is a colon, key is done and value is next
          endofkey = true;  
        }
        if (s[i] != ':' && endofkey){ //if the char is not a colon and colon already found, add char to value string
          value += s[i];
        }
    }
    //prints key and value for testing
    Serial.print("Key: ");
    Serial.println(key);
    Serial.print("Value: ");
    Serial.println(value);
    
    double dVal;
  
    //The code below should be modified depending on how exactly you want the automatic commands to work
    //Probably need to make these global variables
    double xStart;
    double xEnd;
    double yStart;
    double yEnd;
    double zStart;
    double zEnd;
    //a few lines so that the values for certain keys become ints/doubles instead of strings
    if (key == "startX" || key == "endX" || key == "startY" || key == "endY" || key == "startZ" || key == "endZ"){
        const char *mychar = value.c_str();
        dVal = atof(mychar);
        Serial.println(dVal); //prints just the double value
    }

    //assigns double values to the corresponding variable 
    //Since this function only takes 1 part of the command at a time, it needs to store values before passing them to automaticMode function
    if (strcmp(key.c_str(),"startX")==0) {
        xStart = dVal;
    } 
    else if (strcmp(key.c_str(),"endX")==0) {
        xEnd = dVal;
    } 
    else if (strcmp(key.c_str(),"startY")==0) {
        yStart = dVal;
    } 
    else if (strcmp(key.c_str(),"endY")==0) {
        yEnd = dVal;
    } 
    else if (strcmp(key.c_str(),"startZ")==0) {
        zStart = dVal;
    } 
    else if (strcmp(key.c_str(),"endZ")==0) {
        zEnd = dVal;
    } 
    else { Serial.println("ERROR: Invalid Key!"); }
    
}


//This function should take in all of the values from an automatic command and perform the corresponding action
//Not sure what the inputs are right now or what they do
void automaticMode(double xStart, double xEnd, double yStart, double yEnd, double zStart, double zEnd, String mode, float totaltime, float shutterspeed){
    
}


