# Part introduction
## Breadboard
A breadboard is a tool used to build and test electronic circuits without needing to solder anything together. It’s perfect for prototyping and quick electronic projects as you can easily make and change connections.

A breadboard has rows and columns of holes where you can insert components like resistors, wires, and microcontrollers. These holes are connected in certain ways that allow electricity to flow between them, creating a circuit.

Rows: The breadboard has long horizontal rows (typically marked with numbers) where components are connected. If you place components in the same row, they are electrically connected inside the breadboard. These are often used for the main part of the circuit.
Columns: The breadboard has vertical columns of holes, often marked with letters (A, B, C, D, E). These are used to connect different parts of the circuit together. Placing components in the same column does NOT make them electrically connected inside the breadboard, unless there is a connection between the rows they are in

Most breadboards have two long vertical strips on the sides, often marked with + (positive) and - (negative). These are the power rails.

`+ Rail: This is where you connect the positive side of your power supply (e.g., from a battery or a power supply).`
`- Rail: This is where you connect the negative side (ground) of your power supply.`

You can think of these rails as channels for power, so you don’t have to run individual wires for each component.


## LED
An LED is a diode that emits light, as its name would suggest. Due to the semiconductor nature of an LED, it only allows current to flow in one direction, like a one-way gate. The side that current comes into is called the anode and is usually marked with a +, and the side that current comes out of is called the cathode and is usually marked with a -. The LEDs usually denote which leg is the anode (+) by making it the longer leg.


## Resistor
A resistor is used to provide electrical resistance to a circuit. In this circuit, it is used to limit the current being drawn so the LED doesn’t burn out from having too much current being drawn through it.
Ohm’s Law Formula: V = I × R

V = Voltage (measured in Volts, V)
I = Current (measured in Amperes, A)
R = Resistance (measured in Ohms, Ω)

## Microcontroller
A microcontroller is like a tiny computer that can be programmed to do specific tasks. It has a processor (the "brain"), memory (to store instructions), and input/output pins (to connect to buttons, sensors, lights, motors, etc.).


## Shift Register
The SN74HC595N is an 8-bit shift register, meaning it can control 8 outputs using just three control pins from your microcontroller:
Serial Data Input (DS) – Receives the data (1s and 0s) one bit at a time.
Shift Clock (SHCP) – Moves (or "shifts") the data through the register.
Storage Clock (STCP or Latch) – Transfers the shifted data to the outputs.

Instead of directly controlling 8 LEDs with 8 pins from your microcontroller, you:
Send a sequence of 8 bits (e.g., 10101010 for alternating LEDs).
Use the clock signals to shift these bits into the register.
The register stores the data and updates all outputs at once.


## LED Array
An LED array is a group of LEDs arranged in a specific pattern or grid, allowing multiple LEDs to be controlled together. These arrays are used for visual displays, indicators, and lighting effects.
Depending on the design, an LED array can be:
Organized in a matrix (rows and columns) where LEDs share connections, requiring techniques like multiplexing to control them efficiently.


# Section 1: Blinking an LED
## Introduction
In order to make an LED blink, you need to cycle providing and not providing power to the LED. This can be done through analog electronics (like a 555 timer or other integrated circuit), or through a microcontroller, which we will be using.

A microcontroller is a small computer on a single chip that is used to control electronic devices or systems. It’s like the "brain" of an electronic project, but much simpler and smaller than a regular computer. It can take in information from the outside world (like from buttons, sensors, or switches) and then process that information through code that you can write and upload to it. Based on this processing, it can send out commands to other parts of the system (like turning on a light, moving a motor, or displaying something on a screen).

## Circuit Diagram


In order to try to explain how this works, I think it will be easiest to explain how each part works independently, and then it should be pretty self explanatory as to how the entire thing works.


## Schematic
An electrical schematic (or circuit diagram) is a drawing that shows how the electrical components of a circuit are connected together. It's like a map or blueprint for building an electrical circuit. Instead of showing physical details, like where things are placed on a board, a schematic uses symbols to represent the components and lines to show how the current flows between them.

See if you can see the LED and resistor in the schematic for this circuit!



## Code
This circuit uses code to control the microcontroller. I will attach the code below and then describe what it does after:

```
// C++ code
//
void setup()
{
  pinMode(2, OUTPUT);
}

void loop()
{
  digitalWrite(2, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(2, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}
```




## Code Breakdown:
1. `void setup()`
`setup()` is a special function in microcontroller programming that runs once when the microcontroller starts or resets.
Inside the `setup()` function, there is a line:
`pinMode(2, OUTPUT);`
`pinMode(2, OUTPUT)` tells the microcontroller that pin 2 is going to be used as an output. This is because we want to send a signal (either HIGH or LOW) to an external component, like an LED, that is connected to pin 2.
Besides some power pins, the microcontroller has 2 main types of pins, analog and digital:
Digital pins can only have two states: ON or OFF. These are represented as either HIGH (usually 5V or 3.3V, depending on the board) or LOW (0V or ground). Essentially, digital pins deal with binary signals (either 1 or 0).
Analog pins can handle continuous values, not just ON/OFF states. They can read or send values that vary smoothly between a range (e.g., from 0 to 1023 on an Arduino). This allows them to handle analog signals (such as a sensor's reading or controlling the brightness of a light).
The digital pins can be configured to be either an input or an output:
Output pins are used to send signals from the microcontroller to other components (like LEDs, motors, relays, etc.). When you set a digital pin as an output, you are telling the pin to control something, like turning an LED on or off, or sending a signal to activate a switch.
Input pins are used to receive signals from external components or devices (like buttons, sensors, switches, etc.).
When you set a digital pin as an input, you are telling the microcontroller to read data from something connected to that pin.
The analog pins are all inputs and cannot be configured to be outputs. If you wanted to produce a voltage of say 2.5V instead of 3.3V or 5V, you could use a digital pin configured to be an output, as long as it has the Pulse Width Modulation (PWM) feature, but that is beyond the scope of this workshop.
2. `void loop()`
`loop()` is another special function that runs continuously after the setup is complete. The code inside loop() will repeat over and over again, forever.
Inside `loop()`, we have:
`digitalWrite(2, HIGH);`
`digitalWrite(2, HIGH)` turns pin 2 "on." It sends 5V to pin 2, which will make the connected device (like an LED) light up.
`delay(1000);`
`delay(1000)` pauses the program for 1000 milliseconds (or 1 second). This means the LED will stay on for 1 second.
`digitalWrite(2, LOW);`
`digitalWrite(2, LOW)` turns pin 2 "off." It sends 0V to pin 2, which will turn off the LED.
`delay(1000);`
Again, `delay(1000)` pauses the program for another 1 second, keeping the LED off for that time.
So, in summary:
- The LED turns on (pin 2 is set to HIGH).
- It stays on for 1 second (delay).
- The LED turns off (pin 2 is set to LOW).
- It stays off for 1 second (delay).
- Then, the cycle repeats forever.


## Procedure
- Place the ESP in the breadboard so each pin gets its own row. This might require the use of two breadboards.
- Add a jumper wire from the row with the pin labeled “D1” to a spare row on the breadboard. We will be using this D1 pin as our digital output for the LED.
- Add a 1k resistor from the spare row from step 2 to another spare row
- Add an LED from the spare row from step 3 to another spare row. Make sure the anode of the LED is connected to the row from step 3, and the cathode is connected to the spare row
- Add a jumper wire from the row the cathode is in to the ground
- Plug in the microUSB cable to your computer.
- Upload the code above and it should work!
