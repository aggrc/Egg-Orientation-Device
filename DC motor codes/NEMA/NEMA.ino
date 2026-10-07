#include <Adafruit_STSPIN220.h>

const int STEPS_PER_REVOLUTION = 200;

// Arduino Uno connections
const int DIR_PIN = 2;
const int STEP_PIN = 3;
const int MS1_PIN = 4;
const int MS2_PIN = 5;
const int EN_PIN = 6;
const int RST_PIN = 7;

Adafruit_STSPIN220 motor(
  STEPS_PER_REVOLUTION,
  STEP_PIN,
  DIR_PIN,
  MS1_PIN,
  MS2_PIN,
  EN_PIN,
  RST_PIN
);

void setup() {
  Serial.begin(115200);

  // Output-shaft speed
  motor.setSpeed(1);  //  RPM

  motor.setStepMode(STSPIN220_STEP_1_64);

  Serial.println("Motor running at 1 RPM with 1/128 microstepping");
}

void loop() {
  long microstepsPerRevolution =
      STEPS_PER_REVOLUTION * motor.microstepsPerStep();

  
  motor.step(microstepsPerRevolution);
}