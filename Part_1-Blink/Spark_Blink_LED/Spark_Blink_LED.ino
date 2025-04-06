// Blink sketch for SPARK!xHackHardware workshop Spring 2025.
// Released into the Public Domain.

/*
Before compiling, make sure you have:
- installed the ESP8266 runtime by following the instructions here: 
  https://github.com/esp8266/Arduino?tab=readme-ov-file#installing-with-boards-manager
- Selected the correct port for your board (try plugging and unplugging with the dropdown open.
  The one that appears when you plug the board in is the one you want.)
- Selected "LOLIN(WEMOS) D1 mini (clone)" as the board.
*/

void setup()
{
  // Defines D1 as an output, which makes sense as you are outputting power to control the LED
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  // Drives D1 to output 5V, the "high" value
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  
  // Drives D1 to output 0V, the "low" value
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}

