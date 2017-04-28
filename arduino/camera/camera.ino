
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  // Stops
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  delay(2000);
  
  // Takes pictures
  Serial.print("Taking picture");
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  delay(10000);
}
