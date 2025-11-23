//The main goal of this program is to control the angle of a servo motor using the joystick
// the main theme of this program analog input 

#include <Servo.h> // adding the library for the servo motors

Servo myservo;      // create Servo object to control a servo
int joystickX = A0; // analog pin connected to joystick X-axis
int val;            // variable to store the analog reading

void setup() {
  myservo.attach(9);  // attach the servo on pin 9
}

void loop() {
  val = analogRead(joystickX);          // read joystick position (0-1023)
  val = map(val, 0, 1023, 0, 180);      // scale it to servo angle (0-180)
  myservo.write(val);                    // set servo position
  delay(15);                             // small delay for smooth movement
}