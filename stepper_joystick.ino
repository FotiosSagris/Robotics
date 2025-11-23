// The main goal of this program is to control the direction and speed
// of a stepper motor using a joystick.
// The main theme is using analog inputs to control a motor.

#include <Stepper.h>

// Motor constants
const float STEPS_PER_REV = 32;
const float GEAR_RED = 64;
const int STEPS_PER_OUT_REV = STEPS_PER_REV * GEAR_RED;

// Stepper pins using your fixed working wiring
Stepper steppermotor(STEPS_PER_OUT_REV, 8, 9, 10, 11);

// Joystick pins
const int joyX = A1;  // left-right = direction
const int joyY = A0;  // up-down = speed

// Dead zone
const int deadZone = 60;

// Real usable speed range for 28BYJ-48 motor
const int minSpeed = 5;   // slowest RPM
const int maxSpeed = 20;  // fastest RPM (safe max)

void setup() {
}

void loop() {

  // Read joystick
  int xVal = analogRead(joyX);
  int yVal = analogRead(joyY);

  int direction = 0;

  // Determine direction
  if (xVal < 512 - deadZone) {
    direction = -1;  // CCW
  }
  else if (xVal > 512 + deadZone) {
    direction = 1;   // CW
  }
  else {
    direction = 0;   // joystick centered → stop
  }

  // Map speed from Y-axis
  int speed = map(yVal, 0, 1023, minSpeed, maxSpeed);

  // Apply motor control
  if (direction != 0) {
    steppermotor.setSpeed(speed);
    steppermotor.step(direction * 1);  // tiny step = smooth + responsive
  }
}
