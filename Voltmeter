/*
The main goal of this program is to read the bitvalue from the analog input and convert it into voltage
The main theme of this program is analog input processing
*/


void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}
// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // this is the formula to switch the bitvalue to voltage
  float voltage = sensorValue * (5.0 / 1023.0);
  // print out the value you read:
Serial.print("Bitvalue ="); // print whats in between the quotation marks
  Serial.print(sensorValue); // print the value in bits
  Serial.print("\t"); // print a tab space
  Serial.print("Voltage= ");//print whats in between the quotation marks
  Serial.println(voltage); // print the value in voltage
 delay(200);  // delay in between reads for stability
}
