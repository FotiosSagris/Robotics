//The main goal is to read the temperature and the humidity values from the DHT11 and display them on the LCD
//The main theme sensor data acquisiton and LCD output


#include <DHT.h> // include the DHT sensor library
#include <LiquidCrystal.h> // include the LCD library

// ----- DHT Setup -----
#define DHTPIN 8       // DHT11 data pin
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);

// ----- LCD Setup -----
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  dht.begin();   // start communication with the DHT11 
  lcd.begin(16, 2); // initialize the LCD
}

void loop() {
  float temperature = dht.readTemperature();   // read temperature in celcius
  float humidity = dht.readHumidity(); // read the humidity %

  // Display Temperature
  lcd.setCursor(0, 0); // Move cursor to column 0, row 0
  lcd.print("Temp: ");
  lcd.print(temperature); // Print temperature value
  lcd.print((char)223); // Degree symbol
  lcd.print("C   ");

  // Display Humidity
  lcd.setCursor(0, 1); // Move cursor to column 0, row 1
  lcd.print("Hum: ");
  lcd.print(humidity); // Print humidity value
  lcd.print("%   ");

  delay(2000); // Update every 2 seconds
}