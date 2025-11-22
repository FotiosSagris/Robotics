#include <LiquidCrystal.h> // including the LCD Display library

// LCD pin setup
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2); // Initialize the LCD with 16 columns and 2 rows
}

void loop() {
  // Read analog input on A0
  int sensorValue = analogRead(A0);

  // Convert bit value to voltage
  float voltage = sensorValue * (5.0 / 1023.0);

  // LCD Display
  lcd.setCursor(0, 0); // set cursor to column 0, row 0
  // Display the bitvalue
  lcd.print("Bit: ");
  lcd.print(sensorValue);
  lcd.print("    ");

  lcd.setCursor(0, 1); // set cursor to column 0, row 1
  // Display the voltage
  lcd.print("Volt: "); 
  lcd.print(voltage, 2);
  lcd.print("V   ");

  delay(200); // small delay
}
