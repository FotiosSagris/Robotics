#include <LiquidCrystal.h>

// LCD pin setup
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
  lcd.print("Analog Reader");
  delay(1000);
  lcd.clear();
}

void loop() {
  // Read analog input on A0
  int sensorValue = analogRead(A0);

  // Convert bit value to voltage
  float voltage = sensorValue * (5.0 / 1023.0);

  // LCD Display
  lcd.setCursor(0, 0);
  lcd.print("Bit: ");
  lcd.print(sensorValue);
  lcd.print("    ");

  lcd.setCursor(0, 1);
  lcd.print("Volt: ");
  lcd.print(voltage, 2);
  lcd.print("V   ");

  delay(200);
}