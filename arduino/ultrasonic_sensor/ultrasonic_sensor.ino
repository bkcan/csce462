#define DIR_PIN_Rotating 2
#define STEP_PIN_Rotating 3

#define DIR_PIN_UD 12
#define STEP_PIN_UD 13

int trig_R = 4;
int echo_R = 5;

int trig_L = 6;
int echo_L = 7;

int trig_U = 10;
int echo_U = 11;

int trig_D = 8;
int echo_D = 9;


float duration_R;
float distance_R;
float duration_L;
float distance_L;


float duration_U;
float distance_U;
float duration_D;
float distance_D;


void setup() {
  Serial.begin(9600);
  //----for sensor pins----
  pinMode(trig_R, OUTPUT);
  pinMode(echo_R, INPUT);
  pinMode(trig_L, OUTPUT);
  pinMode(echo_L, INPUT);

  pinMode(trig_U, OUTPUT);
  pinMode(echo_U, INPUT);

  pinMode(trig_D, OUTPUT);
  pinMode(echo_D, INPUT);

  //----for motor pins----
  pinMode(DIR_PIN_Rotating, OUTPUT);
  pinMode(STEP_PIN_Rotating, OUTPUT);
  pinMode(DIR_PIN_UD, OUTPUT);
  pinMode(STEP_PIN_UD, OUTPUT);
}

void loop() {
  digitalWrite(trig_R, HIGH);
  delay(10);                //0.01 sec
  digitalWrite(trig_R, LOW);

  duration_R = pulseIn (echo_R, HIGH);
  distance_R = ((34000 * duration_R) / 1000000) / 2; //34000 (sound velocity) (340m/s)

  digitalWrite(trig_L, HIGH);
  delay(10);
  digitalWrite(trig_L, LOW);

  duration_L = pulseIn (echo_L, HIGH);
  distance_L = ((34000 * duration_L) / 1000000) / 2;


  digitalWrite(trig_U, HIGH);
  delay(10);
  digitalWrite(trig_U, LOW);

  duration_U = pulseIn (echo_U, HIGH);
  distance_U = ((34000 * duration_U) / 1000000) / 2;

  digitalWrite(trig_D, HIGH);
  delay(10);
  digitalWrite(trig_D, LOW);

  duration_D = pulseIn (echo_D, HIGH);
  distance_D = ((34000 * duration_D) / 1000000) / 2;



  if ((distance_R > 5 && distance_R < 20) && (distance_L > 5 && distance_L < 20))
  {
    rotateDeg_Right(0, 0.04);
    rotateDeg_Left(0, 0.04);
  }
  else if (distance_L > 5 && distance_L < 20)
  {
    rotateDeg_Left(10, 0.04);
  }
  else if (distance_R > 5 && distance_R < 20)
  {
    rotateDeg_Right(-10, 0.04);
  }

  else if ((distance_U > 5 && distance_R < 20) && (distance_D > 5 && distance_L < 20))
  {
    rotateDeg_Up(0, 0.04);
    rotateDeg_Down(0, 0.04);
  }
  else if (distance_U > 5 && distance_U < 20)
  {
    rotateDeg_Up(-10, 0.04);
  }
  else if (distance_D > 5 && distance_D < 20)
  {
    rotateDeg_Down(10, 0.04);
  }

  Serial.print("distance_L: "); Serial.print(distance_L); Serial.print("cm"); Serial.print("   ,   ");
  Serial.print("distance_R: "); Serial.print(distance_R); Serial.print("cm"); Serial.print("   ,   ");
  Serial.print("distance_U: "); Serial.print(distance_U); Serial.print("cm"); Serial.print("   ,   ");
  Serial.print("distance_D: "); Serial.print(distance_D); Serial.println("cm");
  delay(1000);
}

void rotateDeg_Right(float deg, float speed) {
  //rotate a specific number of degrees (negitive for reverse movement)
  //speed is any number from .01 -> 1 with 1 being fastest - Slower is stronger
  int dir = (deg > 0) ? HIGH : LOW;
  digitalWrite(DIR_PIN_Rotating, dir);

  int steps = abs(deg) * (1 / 0.225);
  float usDelay = (1 / speed) * 70;

  for (int i = 0; i < steps; i++) {
    digitalWrite(STEP_PIN_Rotating, HIGH);
    delayMicroseconds(usDelay);

    digitalWrite(STEP_PIN_Rotating, LOW);
    delayMicroseconds(usDelay);
  }
}

void rotateDeg_Left(float deg, float speed) {
  //rotate a specific number of degrees (negitive for reverse movement)
  //speed is any number from .01 -> 1 with 1 being fastest - Slower is stronger
  int dir = (deg > 0) ? HIGH : LOW;
  digitalWrite(DIR_PIN_Rotating, dir);

  int steps = abs(deg) * (1 / 0.225);
  float usDelay = (1 / speed) * 70;

  for (int i = 0; i < steps; i++) {
    digitalWrite(STEP_PIN_Rotating, HIGH);
    delayMicroseconds(usDelay);

    digitalWrite(STEP_PIN_Rotating, LOW);
    delayMicroseconds(usDelay);
  }
}


void rotateDeg_Up(float deg, float speed) {
  //rotate a specific number of degrees (negitive for reverse movement)
  //speed is any number from .01 -> 1 with 1 being fastest - Slower is stronger
  int dir = (deg > 0) ? HIGH : LOW;
  digitalWrite(DIR_PIN_UD, dir);

  int steps = abs(deg) * (1 / 0.225);
  float usDelay = (1 / speed) * 70;

  for (int i = 0; i < steps; i++) {
    digitalWrite(STEP_PIN_UD, HIGH);
    delayMicroseconds(usDelay);

    digitalWrite(STEP_PIN_UD, LOW);
    delayMicroseconds(usDelay);
  }
}

void rotateDeg_Down(float deg, float speed) {
  //rotate a specific number of degrees (negitive for reverse movement)
  //speed is any number from .01 -> 1 with 1 being fastest - Slower is stronger
  int dir = (deg > 0) ? HIGH : LOW;
  digitalWrite(DIR_PIN_UD, dir);

  int steps = abs(deg) * (1 / 0.225);
  float usDelay = (1 / speed) * 70;

  for (int i = 0; i < steps; i++) {
    digitalWrite(STEP_PIN_UD, HIGH);
    delayMicroseconds(usDelay);

    digitalWrite(STEP_PIN_UD, LOW);
    delayMicroseconds(usDelay);
  }
}

