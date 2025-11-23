// the main goal of this program is to control the direction and speed of a stepper motor with a joystick
//the main theme is analog inputs to control a motor

#include <Stepper.h> // include the stepper motor library

// Motor constants
const float STEPS_PER_REV = 32; 
const float GEAR_RED = 64;
const float STEPS_PER_OUT_REV = STEPS_PER_REV * GEAR_RED;

// Create Stepper instance using output shaft steps
Stepper steppermotor(STEPS_PER_OUT_REV, 8, 10, 9, 11);

// Joystick pins
const int joyX = A1;  // left-right = direction
const int joyY = A0;  // up-down = speed

// Dead zone for X-axis to avoid jitter
const int deadZone = 50;

// Speed range
const int minSpeed = 10;   // RPM
const int maxSpeed = 100;  // RPM

int xVal, yVal;
int direction;
int speed;

void setup() {
}

void loop() {
  // Read joystick
  xVal = analogRead(joyX); // read X axis
  yVal = analogRead(joyY); // read y axis

  // Determine direction
  if (xVal < 512 - deadZone) direction = -1;  // CCW
  else if (xVal > 512 + deadZone) direction = 1; // CW
  else direction = 0; // stop

  // Determine speed from Y-axis
  speed = map(yVal, 0, 1023, minSpeed, maxSpeed);

  // Apply motor movement
  if (direction != 0) {
    steppermotor.setSpeed(speed);         // always positive RPM
    steppermotor.step(direction * 10);    // direction controls sign
  }

  delay(20); // small delay for stability
}
