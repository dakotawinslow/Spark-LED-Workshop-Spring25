// C++ code
//

// Defines D1 as 5, as per the Linux # Specified by the chip
#define D1 5

void setup()
{
  // Defines D1 as an output, which makes sense as you are outputting power to control the LED
  pinMode(D1, OUTPUT);
}

void loop()
{
  // Drives D1 to output 5V, the "high" value
  digitalWrite(D1, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  
  // Drives D1 to output 0V, the "low" value
  digitalWrite(D1, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}

