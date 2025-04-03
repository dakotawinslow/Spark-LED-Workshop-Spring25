/*
  Code for controlling a 545N Shift Register. Adapted from the example at
  https://timodenk.com/blog/shift-register-arduino-library/
  Developed for HackHardware and Spark! Mar 2025
  Released into the public domain.
*/

#include <ShiftRegister74HC595.h>

// create a global shift register object
// parameters: <number of shift registers> (data pin (SER), clock pin (SRCLK), latch pin (RCLK))
ShiftRegister74HC595<1> sr(D4, D2, D3);
 
void setup() { 
  Serial.begin(9600);
}

void loop() {

  // setting all pins at the same time to either HIGH or LOW
  Serial.println("Setting all HIGH");
  sr.setAllHigh(); // set all pins HIGH
  delay(500);
  
  Serial.println("Setting all LOW");
  sr.setAllLow(); // set all pins LOW
  delay(3000); 
  

  // setting single pins
  for (int i = 0; i < 8; i++) {
    
    Serial.print("Setting ");
    Serial.print(i);
    Serial.println(" High");
    sr.set(i, HIGH); // set single pin HIGH
    delay(1000); 
  }
  
  
  // set all pins at once
  uint8_t pinValues = 0b01010101;
  Serial.print("Setting Byte");
  sr.setAll(&pinValues); 
  delay(2000);

  // Add your own code here to build your binary counter. 
  // It should count from 0 to 255 with visually distinct steps.
  // Use whatever method you desire, but I recommend starting with a for() loop.


}
