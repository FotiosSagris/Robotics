/*
The main goal of this program is to read the analog input value from the potentiometer and light up certain LEDS based on the 
values range.
The main theme is analog input
*/


void setup() {
  pinMode(13,OUTPUT); // set pin 13 as an output
  pinMode(12,OUTPUT); // set pin 12 as an output
  pinMode(8,OUTPUT); // set pin 8 as an output
  pinMode(7,OUTPUT); // set pin 7 as an output
  pinMode(2,OUTPUT); // set pin 2 as an output
  pinMode(A0,INPUT); // set pin A0 as an input
}

void loop() {
int bitValue = analogRead(A0); // read the value from A0 and saving it in the integer bitValue

// if bitvalue is smaller than 250, turn on the LED from pin 13
if (bitValue <250){
  digitalWrite(13,1);
  digitalWrite(12,0);
  digitalWrite(8,0);
  digitalWrite(7,0);
  digitalWrite(2,0);
}
 
 // if bitvalue is between 250 and 500, turn on the LED's from pin 13 and 12
if (bitValue > 250 &&  bitValue < 500){
  digitalWrite(13,1);
  digitalWrite(12,1);
  digitalWrite(8,0);
  digitalWrite(7,0);
  digitalWrite(2,0);
}

// if bitvalue is between 500 and 750, turn on the LED's from pin 13,12 and 8
if (bitValue > 500 &&  bitValue < 750){
  digitalWrite(13,1);
  digitalWrite(12,1);
  digitalWrite(8,1);
  digitalWrite(7,0);
  digitalWrite(2,0);
}

// if bitvalue is between 750 and 1000, turn on the LED's from pin 13,12,8 and 7
if (bitValue > 750 &&  bitValue < 1000){
  digitalWrite(13,1);
  digitalWrite(12,1);
  digitalWrite(8,1);
  digitalWrite(7,1);
  digitalWrite(2,0);
}

// if bitvalue is between 1000 and 1250, turn on all the LED's
if (bitValue > 1000 &&  bitValue < 1250){
  digitalWrite(13,1);
  digitalWrite(12,1);
  digitalWrite(8,1);
  digitalWrite(7,1);
  digitalWrite(2,1);
}

}

