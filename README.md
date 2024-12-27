# Auto_Temperature_Regulator
# STM32H743ZI Nucleo-144 Temperature Control with Fan

## Overview

This STM32H743ZI Nucleo-144 project measures temperature using a thermistor and controls a fan based on a specified threshold temperature. The project includes the necessary code, circuit connections, and instructions to replicate the setup.

## Table of Contents

- [Features](#features)
- [Hardware Requirements](#hardware-requirements)
- [Circuit Connection](#circuit-connection)
- [Software Requirements](#software-requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)
- [Acknowledgements](#acknowledgements)

## Features

- Measures temperature using a thermistor.
- Controls a fan based on a specified threshold temperature.
- Provides a simple STM32CubeIDE project for easy understanding and modification.

## Hardware Requirements

- STM32H743ZI Nucleo-144 development board
- Thermistor (MF72 10D11 or similar)
- Resistor (10k ohms for thermistor voltage divider)
- 1K Ohms and 10k for amplifier system for the fan
- BC547 NPN transistor
- Fan
- 9V battery
- Breadboard and jumper wires

## Circuit Connection

### Thermistor Setup:

1. Connect one end of the thermistor to the `3.3V` pin on the STM32H743ZI Nucleo-144.
2. Connect the other end of the thermistor to one leg of a `10k-ohm` resistor.
3. Connect the other leg of the `10k-ohm` resistor to the `A0` pin on the STM32H743ZI Nucleo-144.

### Voltage Divider Circuit:

1. Connect the junction between the thermistor and the `10k-ohm` resistor to the `A0` pin on the STM32H743ZI Nucleo-144.
2. Connect the `A0` pin to the ground (`GND`) on the STM32H743ZI Nucleo-144.

### BC547 Transistor:

1. Connect the collector (`C`) of the BC547 transistor to `pin 9` on the STM32H743ZI Nucleo-144.
2. Connect the emitter (`E`) of the BC547 transistor to the ground (`GND`) on the STM32H743ZI Nucleo-144.
3. Connect the base (`B`) of the BC547 transistor through a `1k-ohm` resistor to `pin 9` on the STM32H743ZI Nucleo-144.

### Fan:

1. Connect the positive (power) side of the fan to an external power supply or a high-current source.
2. Connect the negative (ground) side of the fan to the collector (`C`) of the BC547 transistor.

### Power Supply:

1. Connect the `9V` battery positive terminal to the `VIN` pin on the STM32H743ZI Nucleo-144.
2. Connect the `9V` battery negative terminal to the ground (`GND`) on the STM32H743ZI Nucleo-144.

![Circuit Diagram](/images/circuit_diagram.png)

## Software Requirements

- Arduino ide

## Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/Airlectric/Auto_Temp_Regulator.git


## Usage
## How the System Functions

The STM32H743ZI Nucleo-144 Temperature Control with Fan project functions by measuring the temperature using a thermistor and controlling a fan based on a specified threshold temperature. Here's a step-by-step explanation of how the system works:

1. **Temperature Measurement:**
   - The system uses a thermistor (MF72 10D11 or similar) to measure the temperature.
   - The thermistor is connected in a voltage divider circuit with a 10k-ohm resistor.
   - The analog reading from the A0 pin is converted to resistance using the voltage divider formula.
   - The resistance value is then used in the Steinhart-Hart equation to calculate the temperature in Celsius.

2. **Fan Control Logic:**
   - The system compares the measured temperature with a predefined threshold temperature (`thresholdTemperature`).
   - If the temperature exceeds the threshold, the fan control logic is triggered.
   - The system uses a BC547 NPN transistor to control the fan. When the temperature is above the threshold, the transistor is turned on; otherwise, it is turned off.

3. **LED Indicators:**
   - The system includes LED indicators for visual feedback.
   - LD1 and LD2 LEDs are used to indicate the system is active and controlling the fan.
   - LD3 LED indicates that the fan is off.

4. **Threshold Temperature:**
   - The `thresholdTemperature` variable in the code determines the temperature at which the fan should be turned on.
   - Users can adjust this threshold value based on their specific requirements.
   - The system checks if the measured temperature exceeds this threshold to activate the fan.

5. **Power Supply:**
   - The system is powered by a 9V battery, and the positive terminal is connected to the VIN pin on the STM32H743ZI Nucleo-144.
   - The negative terminal of the 9V battery is connected to the ground (GND) on the STM32H743ZI Nucleo-144.

6. **External Fan Power:**
   - The fan is powered by an external power supply or a high-current source.
   - The positive side of the fan is connected to the external power source.
   - The negative side of the fan is connected to the collector (C) of the BC547 transistor.

7. **Arduino IDE Compatibility:**
   - This project is developed using the Arduino IDE for compatibility with STM32 boards.
   - Users can upload the code using the Arduino IDE and monitor the temperature and fan control via the Serial Monitor.

8. **Installation and Usage:**
   - The system can be cloned from the GitHub repository and opened in the Arduino IDE.
   - After uploading the code to the STM32H743ZI Nucleo-144, the temperature and fan control can be monitored via the Serial Monitor.


## Contributing

### Bug Reports

If you find a bug in the project, please open an issue and provide detailed information about the bug.

### Feature Requests

If you have a feature request, please open an issue and describe the new feature you would like to see.

### Code Contributions

We welcome code contributions. If you want to contribute to the project, please fork the repository and submit a pull request with your changes.

# License

This project is licensed under the [MIT License](LICENSE).

---

# Acknowledgments

Special thanks to the Computer Architecture Team at the University of Ghana, Legon, for their contributions and collaboration on this project:

- DOE AGUDEY DANIEL
- TWUM DANSO
- KELVIN FIADOR
- FAROUK UMAR SEDICK
- MICHEAL APPIAH

