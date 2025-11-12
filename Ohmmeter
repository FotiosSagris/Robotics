/*
The main goal of this program is to find the resistance of an unknown resistor and display it on the LCD display
The main theme is analog input processing and display using the LCD
*/


#include <LiquidCrystal.h>  // we are including the liquid crystal library in our program

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; // define the lcd pin connections
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); // create an LCD object with the pins that we identified before

// we are defining a custom character pattern for the ohm symbol
byte ohmChar[8] = {
  B00000,
  B01110,
  B10001,
  B10001,
  B10001,
  B01010,
  B11011,
  B00000,
};

const int analogPin = A0; // setting the analog input pin as a constant integer
const float R_known = 10000.0;  // 10kΩ known resistor
const float Vin = 5.0;          // Input voltage

void setup() {
  lcd.begin(16, 2); // initialize the lcd display with 16 columns and 2 lines
  lcd.createChar(0, ohmChar); // load the ohm symbol
}

void loop() {
  int bitValue = analogRead(analogPin); // read the analog pin and store the results in the integer bitValue
  float Vout = (bitValue * Vin) / 1023.0; // convert the bitvalue reading into voltage

// this is the formula to find the unknown reistor
  float R_unknown = R_known * (Vout / (Vin - Vout));

  lcd.clear(); // clear the LCD display
  lcd.setCursor(0, 0); // start on the first line first column
  lcd.print("Resistance:"); // display on the LCD the word Resistance:

  lcd.setCursor(0, 1); // skip a line
  lcd.print(R_unknown, 1); // display the value of the unknown resistor
  lcd.write(byte(0)); // Print custom Ohm symbol

  delay(1000); // Small delay to stabilize display
}
