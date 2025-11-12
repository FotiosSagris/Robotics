/*
The main goal of this program is to find the resistance of an unknown resistor and display it on the Serial Monito
The main theme of this program is analog input processing and serial data display
*/

const int analogPin = A0;        // Define the analog input pin
const float R_known = 10000.0;   // Known resistor value: 10kΩ
const float Vin = 5.0;           // Input voltage

void setup() {
  Serial.begin(9600);            // Initialize Serial communication at 9600 bps
}

void loop() {
  int bitValue = analogRead(analogPin);           // Read the analog pin and store the value
  float Vout = (bitValue * Vin) / 1023.0;        // Convert the bit value to voltage

  // Calculate the unknown resistor using this formula
  float R_unknown = R_known * (Vout / (Vin - Vout));

  // Print results to the Serial Monitor
  Serial.print("Resistance: ");       // Label
  Serial.print(R_unknown, 1);         // Print value with 1 decimal place
  Serial.println(" Ω");               // Add Ohm symbol

  delay(1000); // Wait 1 second between readings
}