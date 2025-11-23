// The main goal is to measure the distance using an ultrasonic sensor and display it on the LCD
// the main theme of this program sensor measurement and LCD Display

#include <LiquidCrystal.h> // include the library for the LCD

// LCD pin setup
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Ultrasonic sensor pins
const int trigPin = 9; //setting the trigger pin to send the ultrasonic pulse
const int echoPin = 10; // setting the echo pin the receive the pulse

// Variables
long duration; // stores the time for the pulse to return
float distance; // stores calculated distance in centimeters

void setup() {
  // LCD setup
  lcd.begin(16, 2);

  // Ultrasonic setup
  pinMode(trigPin, OUTPUT); // setting the trigger pin as an output
  pinMode(echoPin, INPUT); // setting the echo pin as an input
}

void loop() {
  // Send a short LOW pulse to ensure a clean HIGH pulse later
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Send the trigger pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echo time 
  duration = pulseIn(echoPin, HIGH);

  // Convert time to distance (cm)
  distance = (duration * 0.0343) / 2;

  // Display on LCD
  lcd.setCursor(0, 0); //first row
  lcd.print("Distance:");
  lcd.setCursor(0, 1); // second row
  lcd.print(distance); // prints the distance value
  lcd.print(" cm   "); // spaces clear leftover characters

  delay(500); // refresh every 0.5 seconds
}
