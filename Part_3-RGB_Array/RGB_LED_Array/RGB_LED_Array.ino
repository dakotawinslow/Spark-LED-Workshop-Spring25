// Developed for HackHardware and Spark! Mar 2025
// Released into the public domain.

#include <Adafruit_NeoPixel.h>

#define LED_COUNT   64    // Number of LEDs in the strip

Adafruit_NeoPixel strip(LED_COUNT, D1, NEO_GRB + NEO_KHZ800);

void setup() {
    strip.begin();
    strip.show();         // Initialize all pixels to 'off'
}

void loop() {
    rainbowCycle(20, 100); // Reduce brightness to 100 (max 255)
}

// Function to set a single color - Not used in the loop right now so currenly never run.
void setColor(uint8_t red, uint8_t green, uint8_t blue) {
    for (int i = 0; i < LED_COUNT; i++) {
        strip.setPixelColor(i, strip.Color(red, green, blue));
    }
    strip.show();
}

// Function to cycle through the rainbow
void rainbowCycle(int wait, uint8_t brightness) {
    for (long firstPixelHue = 0; firstPixelHue < 65536; firstPixelHue += 256) {
        for (int i = 0; i < strip.numPixels(); i++) {
            int pixelHue = firstPixelHue + (i * 65536L / strip.numPixels());
            strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue, 255, brightness)));
        }
        strip.show();
        delay(wait);
    }
}
