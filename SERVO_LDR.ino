/*The main goal of this program is to measure the light intensity using and LDR and use the servo motor as an indicator 
by rotating it based on the light level
The main theme of this program is analog sensor input controlling servo position
*/ 

#include <Servo.h> // include the servo library

Servo myservo;        // create Servo object
int potpin = A0;      // analog pin for LDR
int val;              // raw analog value
int angle;            // mapped servo angle

void setup() {
  Serial.begin(9600); // start the serial monitor
  myservo.attach(9);  // attach servo to pin 9
}

void loop() {
  val = analogRead(potpin);           // read ldr value
  angle = map(val, 0, 1023, 0, 180); // map to servo angle
  myservo.write(angle);               // move servo
  Serial.println(angle);              // print just the servo angle
  delay(500);                         // small delay for stability
}