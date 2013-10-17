/*
  Blink
 Turns on an LED on for one second, then off for one second, repeatedly.
 
 This example code is in the public domain.
 */

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int leds[] = {6,7,13};
int ledSize = 3;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  for (int i = 0; i < ledSize; i++){
    pinMode(leds[i], OUTPUT);
  }    
}

// the loop routine runs over and over again forever:
void loop() {
  for (int i = 0; i < ledSize; i++){
    digitalWrite(leds[i], HIGH);   // turn the LED on (HIGH is the voltage level)
  }
  delay(1000);
  for (int i = 0; i < ledSize; i++){
    digitalWrite(leds[i], LOW);    // turn the LED off by making the voltage LOW
  }
  delay(1000);               // wait for a second
  
}

