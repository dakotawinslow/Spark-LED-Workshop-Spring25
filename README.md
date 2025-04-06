#  introduction
In this workshop, we will learn how to use the Arduino IDE to program a microcontroller to control lights of various complexity.

# Part 1: Blinking an LED
## Introduction
We will begin with the microcontroller equivilent of "Hello, World!": blinking an LED light. This is a great exercise to do with any new setup to make sure evrything works before moving on to more complex systems. 

We will begin by blinking the LED built into the board, then you will modify the given code to blink your own LED. But first, let's familiarize ourselves with the components of our circuit.

## Components 
### Breadboard
A breadboard is a tool used to build and test electronic circuits without needing to solder anything together. It’s perfect for prototyping and quick electronic projects as you can easily make and change connections.

A breadboard has rows and columns of holes where you can insert components like resistors, wires, and microcontrollers. These holes are connected in certain ways that allow electricity to flow between them, creating a circuit.

Rows: The breadboard has long horizontal rows (typically marked with numbers) where components are connected. If you place components in the same row, they are electrically connected inside the breadboard. These are often used for the main part of the circuit.

Columns: The breadboard has vertical columns of holes, often marked with letters (A, B, C, D, E). These are used to connect different parts of the circuit together. Placing components in the same column does NOT make them electrically connected inside the breadboard, unless there is a connection between the rows they are in.

Most breadboards have two long vertical strips on the sides, often marked with + (positive) and - (negative). These are the power rails.

\+ Rail: This is where you connect the positive side of your power supply (e.g., from a battery or a power supply).

\- Rail: This is where you connect the negative side (ground) of your power supply.

You can think of these rails as channels for power, so you don’t have to run individual wires for each component.

![Green lines indicate connections](https://www.losant.com/hs-fs/hubfs/Blog/how-to-use-breadboard/breadboard-diagram.png?width=666&name=breadboard-diagram.png)

### LED (Light Emitting Diode)
An LED is a diode that emits light, as its name would suggest. Due to the semiconductor nature of an LED, it only allows current to flow in one direction, like a one-way gate. The side that current comes into is called the anode and is usually marked with a `+`, and the side that current comes out of is called the cathode and is usually marked with a `-`. The LEDs usually denote which leg is the anode (`+`) by making it the longer leg, and/or by molding a flat side into the capsule.

![LED Diagram](https://europe1.discourse-cdn.com/arduino/original/4X/c/0/c/c0cc8e2297a68de9713e2bdff62b85ce4fbc65fa.png)

### Resistor
A resistor is used to provide electrical resistance to a circuit. In this circuit, it is used to limit the current being drawn so the LED doesn’t burn out from having too much current being drawn through it.
Ohm’s Law Formula: V = I × R

- V = Voltage (measured in Volts, V)
- I = Current (measured in Amperes, A)
- R = Resistance (measured in Ohms, Ω)

![100 Ohm Resistors](https://encrypted-tbn0.gstatic.com/shopping?q=tbn:ANd9GcQ9bISf2scgrVUqt2gAAklB25g8FknBzL7S1dIcPoDOIoQgloFsD11wAgCnG9QJ4AZ4GCofcr1SLRBh8bfzPvyCCh-NhKIGaddxsSbSNr0N4xDLWIhw_IgoZg)

### Microcontroller
A microcontroller is like a tiny computer that can be programmed to do specific tasks. It has a processor (the "brain"), memory (to store instructions), and input/output pins (to connect to buttons, sensors, lights, motors, etc). In our case, we are using a microcontroller called ESP8266. Our microcontroller is in the form of a development board, which adds some helper circuitry like a USB communication chip, voltage regulator, and status LEDs. Our devboard is a clone of the popular open-source Wemos D1 mini.

Be careful if you google search for this board - do not confuse it with the also very popular ESP32.

![Wemos D1 Mini Pinout](https://miro.medium.com/v2/resize:fit:1400/1*YKc8KpAfMrlhrOLmNjdRwQ.png)


## Schematic
An electrical schematic (or circuit diagram) is a drawing that shows how the electrical components of a circuit are connected together. It's like a map or blueprint for building an electrical circuit. Instead of showing physical details, like where things are placed on a board, a schematic uses symbols to represent the components and lines to show how the current flows between them. Schematics are generally abstract representations, as below

![A simple light switch circuit](/Part_1-Blink/Part-1-circuit.png)

For this workshop, we will give you build diagrams, which show you exactly how to lay your components out. This method is a bit more useful for quickly getting started.

![Part 1 Breadboard Diagram](/Part_1-Blink/Blink_Breadboard_bb.png?raw=true)


## Environment Setup
In order to program your microcontroller, you need a development environment. While you can use any text editor to write the actual code for this project, you will need to use the Arduino IDE to compile and upload your code tothe board. As an added bonus, the arduino IDE manages your packages as well, making the process of writing microcontroller code quick and easy. As a bonus, it's part of a massive open-source software system that makes it easy to find support libraries for nearly every microcontroller and periphrial you can imagine.

You will want to install the most recent version of the Arduino IDE for your computer from [arduino.cc](https://www.arduino.cc/en/software).

After installing Arduino, there is a small extra step to add support for our particular microcontroller board. Visit https://github.com/esp8266/Arduino?tab=readme-ov-file#installing-with-boards-manager and follow the instructions to add the ESP8266 runtime using the boards manager. 

## Code
This circuit uses code to control the microcontroller. You can find this code in the [Part_1-Blink folder](/Part_1-Blink/Spark_Blink_LED/Spark_Blink_LED.ino). Let's look at it all together, then go through it line-by-line:

```
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}
```




### Code Breakdown:
`void setup()`

`setup()` is a special function in microcontroller programming that runs once when the microcontroller starts or resets.
Inside the `setup()` function, there is a line:

`pinMode(LED_BUILTIN, OUTPUT);`

`pinMode(LED_BUILTIN, OUTPUT)` tells the microcontroller that pin `LED_BUILTIN` is going to be used as an output. What pin *is* that, you ask? You can find out! `LED_BUILTIN` is a **Precompiler Macro**, which is simply a string of characters that gets replaced by a differrent string just before compiling. In the Arduino IDE (V2 and greater only), we can right-click any macro and select "Go to Definition" to see what it resolves to. Try it and you will find that `LED_BUILTIN` is just a stand-in for `2`. The same process is used for `D0`, `D1`, etc. Why not just use the true name of the pin in your code? Abstract pin names make code more portable. If some other board uses pin 13 for its `LED_BUILTIN` (Like the popular Arduino Uno), you can compile the same code for both boards and both will work as expected. 

Besides some power pins, the microcontroller has 2 main types of pins, analog and digital:

- Digital pins can only have two states: ON or OFF. These are represented as either HIGH (3.3V for us, but sometimes 5V on other boards) or LOW (0V or ground). Essentially, digital pins deal with binary signals (either 1 or 0).

- Analog pins can handle continuous values, not just ON/OFF states. They can read or send values that vary smoothly between a range (e.g., from 0 to 1023 on an Arduino). This allows them to handle analog signals (such as a sensor's reading or controlling the brightness of a light).

The digital pins can be configured to be either an input or an output:

Output pins are used to send signals from the microcontroller to other components (like LEDs, motors, relays, etc.). When you set a digital pin as an output, you are telling the pin to control something, like turning an LED on or off, or sending a signal to activate a switch.
Input pins are used to receive signals from external components or devices (like buttons, sensors, switches, etc.).

When you set a digital pin as an input, you are telling the microcontroller to read data from something connected to that pin.

The analog pins are all inputs and cannot be configured to be outputs. If you wanted to produce a voltage of say 2.5V instead of 3.3V or 5V, you could use a digital pin configured to be an output, as long as it has the Pulse Width Modulation (PWM) feature, but that is beyond the scope of this workshop.

`void loop()`

`loop()` is another special function that runs continuously after the setup is complete. The code inside loop() will repeat over and over again, forever.
Inside `loop()`, we have:

`digitalWrite(LED_BUILTIN, HIGH);`

`digitalWrite(LED_BUILTIN, HIGH)` turns pin 2 "on." It sends 5V to pin 2, which will make the connected device (like an LED) light up.

`delay(1000);`

`delay(1000)` pauses the program for 1000 milliseconds (or 1 second). This means the LED will stay on for 1 second.

`digitalWrite(LED_BUILTIN, LOW);`

`digitalWrite(LED_BUILTIN, LOW)` turns pin 2 "off." It sends 0V to pin 2, which will turn off the LED.

`delay(1000);`
Again, `delay(1000)` pauses the program for another 1 second, keeping the LED off for that time.

So, in summary:
- The LED turns on (pin 2 is set to HIGH).
- It stays on for 1 second (delay).
- The LED turns off (pin 2 is set to LOW).
- It stays off for 1 second (delay).
- Then, the cycle repeats forever.


## Your turn
Play around with the code provided. Once you can successfully blink the onboard LED, try to modify the given code to blink the external LED that is shown in the build diagram above. Remember to use `D5`, not `5`, when referring to the pin marked D5 (and likewise for all maked pins).

# Part 2: Shift Register
## Introduction
In the first section, we learned how to blink an LED. Controlling just a few outputs can be very useful, but what if we wanted to make a control panel with a dozen LEDs? We would quickly run out of pins on our microcontroller. Let's learn how to get more control out of just a few pins with a handy tool called a **Shift Register**.

## Components
### Shift Register
The SN74HC595N is an 8-bit shift register, meaning it can control 8 outputs using just three control pins from your microcontroller:

- Serial Data Input (DS) – Receives the data (1s and 0s) one bit at a time.

- Shift Clock (SHCP) – Moves (or "shifts") the data through the register.

- Storage Clock (STCP or Latch) – Transfers the shifted data to the outputs.

Instead of directly controlling 8 LEDs with 8 pins from your microcontroller, you:

- Send a sequence of 8 bits (e.g., 10101010 for alternating LEDs).

- Use the clock signals to shift these bits into the register.

- The register stores the data and updates all outputs at once.

We will use a library to handle the serial commnication here, which makes using the Shift Register very easy.

![74HC595 Shift Register Pinout](https://i0.wp.com/dronebotworkshop.com/wp-content/uploads/2020/03/74HC595-pinout.jpeg?resize=750%2C422&ssl=1)

## Schematic
Reconstruct your breadboard so that it looks like this. This circuit is a bit more complex than the last one, so take your time and make sure that everything is plugged where it should be.

![Part 2 Diagram](/Part_2-Shift_Register/SR_Breadboard_bb.png)

## Environment Setup
We are going to be using a new library for this section. You can install it with the library manager (the books icon in the sidebar of the Arduino IDE). Search for `ShiftRegister74HC595`. Make sure you install the library with that exact name, written by Timo Denk.

## Code 
This code can be found in the Part_2-Shift_Register folder.

```
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
}
```

Let's go over some of the new things we are seeing here.

First off is `#include <ShiftRegister74HC595.h>`. This line tells the precompiler to bring in all the code from our shift register library so we can use objects defined in that library. It is analogous to an `import` statement in Python.

Next is `ShiftRegister74HC595<1> sr(D4, D2, D3);`. This line creates an instance of a new Serial Register object, defines which physical pins its attached to, and names it `sr`. Note the `<1>` at the end of the first term. This is the number of shift registers we have - they can actually be daisy chained to get even *more* outputs if you need them.

Our final big new concept is `Serial.begin(9600);`. This line gives us some debuggin capability by opening up a serial connection on the USB port, which the Arduino IDE's Serial Monitor tool can read. This lets us print debugging statements and updates to the console, just like a program that runs on your PC. 9600 here is the baud rate - the speed which we communicate. You will want to make sure that the same baud rate is set on your serial monitor when you connect.

The rest of the code gives examples of the various ways to interact with the Shift Register: setting all pins to the same value, setting individual pins, and setting all at once via bitstring. Note the use of a for() loop in the individual pins section - if you have never written a for loop in C/C++ before, make a note of the syntax for later.

## Your Turn
Build the circuit and run the demo code; you should see the lights change as the serial monitor prints out each step. Once you get it working, add a new block (or a whole new sketch, if you prefer) that counts up, in binary, on the LEDs. Each step can be al long or as short as you like, as long as they are distinguishable. feel free to do this however seems best to you, but you should use the shift register to drive your LEDs.

# Part 3: RGB LED Matrix
## Introduction
In the last section, we learned how to serialize data by sending 8 bits of information along one wire (plus another two wires for timing). Can we do better than that? For controlling LEDs, the answer is yes! In the last 15 years, aRGB LEDs (addressable red-green-blue light emitting diodes) have changed the landscape of digital lighting, making it easier than ever to put hundreds of arbitrary colored lights in nearly any device or space with just one control wire. Let's learn how!

## Components
### LED Array
An LED array is a group of LEDs arranged in a specific pattern or grid, allowing multiple LEDs to be controlled together. These arrays are used for visual displays, indicators, and lighting effects.

Our array is composed of WS2812 LED modules (commonly referred to under the AdaFruit trademarked name NEOPIXELS), which use a clever messaging system to set every LED in the chain without requiring an individual wire for every LED. In fact, you can set the individual brightness for each color channel at each position - all with one wire!

They are controlled by creating a packet of data that contains data for every pixel in one big stack. The entire stack is fed into the first pixel, which pops off the first RGB values, sets itself to them, and then passes the stack along to the next pixel. If the pixels are all lined up, we reliably send data to any arbitrary pixel by just passing it down the chain (and making sure the stgack started out the right size).

Again, we use a library to help us with the communications protocol. Communications libraries make it possible to work with very complicated components by abstracting them into simple functions. 

![LED Array](https://m.media-amazon.com/images/I/61vtdV-ssnL._AC_SL1500_.jpg)

![LED Layout](https://m.media-amazon.com/images/I/71AHPq-bDKL._AC_SL1500_.jpg)

## Schematic
You don't have to disassemble the prior setup if you don't to, but be careful that there are no conflicts (two objects should not be connected to the same microcontroller pin).

![Part 3 Diagram](/Part_3-RGB_Array/RGB_Array_Breadboard_bb.png)

## Environment Setup
Make sure to install the Adafruit Neopixel Library using the Arduino Library Manager.

## Code
```
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
```

New features this time:

`#define LED_COUNT   64`: We saw this indirectly in the first section, but now we define our own macro. Doing this makes it easy to switch to a differrent size array in the future.

For the functions related to the `Adafruit_NeoPixel strip()` object, it's best to review the documentation at [adafruit](https://learn.adafruit.com/adafruit-neopixel-uberguide/arduino-library-use), where there are many other tutorials to look over.

## Your Turn


After reviewing the above code, it's time to build something of your own! This time, the world is your oyster - you can do anything you like! Some ideas include:
- Changing the color based on the state of pins on the microcontroller (take a look at [digitalread()](https://docs.arduino.cc/language-reference/en/functions/digital-io/digitalread/) for detecting pin values)
- Drawing letters or images on the array (have a look at the [Adafruit NeoMatrix library](https://learn.adafruit.com/adafruit-neopixel-uberguide/neomatrix-library))
- Setting up a simple webpage to control the array with over WiFi ([See this Tutorial](https://randomnerdtutorials.com/esp32-esp8266-input-data-html-form/))

Or anything else you can think of! Feel free to ask any of the HackHardware staff if you want more information about how to make your idea a reality.
