#include <LiquidCrystal.h>

// LCD pin setup
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Ultrasonic sensor pins
const int trigPin = 9;
const int echoPin = 10;

// Variables
long duration;
float distance;

void setup() {
  // LCD setup
  lcd.begin(16, 2);
  lcd.print("Distance Meter");
  delay(1000);
  lcd.clear();

  // Ultrasonic setup
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Send a short LOW pulse to ensure a clean HIGH pulse later
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Send the trigger pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo time
  duration = pulseIn(echoPin, HIGH);

  // Convert time to distance (cm)
  distance = (duration * 0.0343) / 2;

  // Display on LCD
  lcd.setCursor(0, 0);
  lcd.print("Distance:");
  lcd.setCursor(0, 1);
  lcd.print(distance);
  lcd.print(" cm   "); // spaces clear leftover characters

  delay(500); // refresh every 0.5 seconds
}
