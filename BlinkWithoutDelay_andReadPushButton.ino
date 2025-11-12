/*
The main goal of this program is to blink an LED and display the value of the pushbutton on the serial monitor at the same time. 
Learning how to not use delay
The main theme of this program digital input and output
*/

const int LED_PIN = 13;           // LED connected to pin 13
const int BUTTON_PIN = 2;         // Pushbutton connected to pin 2
const int INTERVAL = 1000;        // Blink interval in milliseconds

unsigned long previousMillis = 0; // Last time LED was toggled
bool ledState = LOW;              // Tracks LED state (OFF by default)

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);  // Button active LOW
  Serial.begin(9600);

  digitalWrite(LED_PIN, ledState);    // Ensure LED starts OFF
}

void loop() {
  unsigned long currentMillis = millis();

  // --- Blink LED without delay() ---
  if (currentMillis - previousMillis >= INTERVAL) {
    previousMillis = currentMillis;

    // Toggle LED each interval
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState);
  }

  // --- Read and display button state ---
  bool buttonPressed = !digitalRead(BUTTON_PIN); // Active LOW
  Serial.print("Button: ");
  Serial.println(buttonPressed ? "Pressed" : "Released");
}
