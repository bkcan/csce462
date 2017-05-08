#include <Wire.h>

void setup() {
  Wire.begin(9);                // join i2c bus with address #9
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  delay(100);
}


// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
    String command = "";
    String key = "";
    String value = "";
    bool endofkey = false;
    int index = 0;
    while (0 < Wire.available()) { // loop through all chars
      char c = Wire.read(); // receive byte as a character
      command += c;
      if (c != ':' && !endofkey){ //if the char is not a colon and no colon found, add char to key string
          key += c;
        }
      if (c == ':'){ ////if the char is a colon, key is done and value is next
          endofkey = true;  
        }
      if (c != ':' && endofkey){ //if the char is not a colon and colon already found, add char to value string
          value += c;
        }
     
    }
    Serial.print("Command: ");
    Serial.println(command);         // prints the command for testing
 
    //prints key and value for testing
    Serial.print("Key: ");
    Serial.println(key);
    Serial.print("Value: ");
    Serial.println(value);
    
    double dVal; //double value

    //a few lines so that the values for certain keys(specified in if statement) become ints/doubles instead of strings
    if (key == "photo" ){
        const char *mychar = value.c_str();
        dVal = atof(mychar);
        Serial.println(dVal); //prints just the double value
    }
    
    //if (command == "up") { rotateStepper2(45);}
    //if (command == "down") { rotateStepper2(-45);}
    //if (key == "photo") { takePicture(dVal);}
}

void takePicture(double timer) {
  digitalWrite(3, HIGH);
  digitalWrite(5, HIGH);
  
  // Takes pictures
  Serial.print("Taking picture");
  digitalWrite(5, LOW);
  digitalWrite(3, LOW);
  delay(timer); // delay = how long shutter suppose to be

   // Stops
  digitalWrite(5, HIGH);
  digitalWrite(3, HIGH);
}

