
#define DIR_PIN_UD 2
#define STEP_PIN_UD 3

int trig_U = 10;
int echo_U = 11;

int trig_D = 8;
int echo_D = 9;

float duration_U;
float distance_U;
float duration_D;
float distance_D;


void setup() {
  Serial.begin(9600);
  //----for sensor pins----
  pinMode(trig_U, OUTPUT);
  pinMode(echo_U, INPUT);

  pinMode(trig_D, OUTPUT);
  pinMode(echo_D, INPUT);

  //----for motor pins----
  pinMode(DIR_PIN_UD, OUTPUT);
  pinMode(STEP_PIN_UD, OUTPUT);
}

void loop() {
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

  if ((distance_U > 5 && distance_U < 20) && (distance_D > 5 && distance_D < 20))
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

  Serial.print("distance_U: "); Serial.print(distance_U); Serial.print("cm"); Serial.print("   ,   ");
  Serial.print("distance_D: "); Serial.print(distance_D); Serial.println("cm");

  delay(300);
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

