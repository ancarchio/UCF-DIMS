# Using This Folder
## DIMS-Application.zip
This folder contains the project files for the DIMS WinForms App. This will allow you to edit the application. Download and extract the zip and open the solution in your IDE of choice (Visual Studio is recommended, as it was used to create the original application)

## Arduino Program
1. DIMS.ino
2. DIMS.h
3. InjectProcess.cpp

Download all 3 program files and open in the Arduino IDE.

The following libraries are needed:
* Arduino and Wire (both included with Arduino IDE)
* [Keypad](https://playground.arduino.cc/Code/Keypad/) by Mark Stanley and Alexander Brevig
* [Adafruit SSD1306](https://github.com/adafruit/Adafruit_SSD1306) by Adafruit
* [MAX6675 Library](https://github.com/adafruit/MAX6675-library) by Adafruit

# Input/Output Indexes

The communication between the Arduino and the WinForms App is done using Serial communication with the following format:
>Index.Value

The index is always two characters, and the value can any integer or float\
Error codes follow the same format, and can be found in detail on the main README, but a summarized version can be found below.
## Input Indexes (sending to Arduino, must be in computer entry mode to work)

#### NT.____: "Nozzle Temperature"
- Sets desired temperature, accepts float

#### HT.____: "Heat Time"
- Sets heat time, accepts float. Value will be in minutes

#### WT.____: "Wait Time"
- Sets hold time, accepts float. Value will be in seconds

#### CT.____: "Cool Time"
- Sets cool time, accepts float. Value will be in minutes

#### PT.1: "Process Start"
- Begins injection process. Only accepts value = 1
- Sets processStart = 1

#### H1.____: "Heaters"
- value = 1: Turns on heaters
- value = 0: Turns off heaters

#### S1.____: "Solenoids"
- value = 1: Turns on solenoids (injects)
- value = 0: Turns off solenoids (raises)

#### F1.____: "Fans"
- value = 1: Turns on fans
- value = 2: Turns off fans


## Output Indexes (Sending data to WinForms App)

#### T1.____: "Barrel Temperature 1" (BT1)
#### T2.____: "Barrel Temperature 2" (BT2)
#### T3.____: "Electronics Temperature" (ET)
#### T4.____: "Mold Cavity Temperature" (MT)

#### G1.____: "Gate Sensor 1"
- value = 1: Gate sensor open (door open)
- value = 2: Gate sensor closed (door closed)

#### G2.____: "Gate Sensor 2"
- value = 1: Gate sensor open (door open)
- value = 2: Gate sensor closed (door closed)

#### IP.____: "Injection Process"
- Indicates current stage of injection process
- value = 1: Heating
- value = 2: Injecting then holding
- value = 3: Cooling
- value = 4: Complete

#### PT.____: "Process Time"
- Sets progress bar value = $\frac{Current Time - Start Time}{Cycle Step Time}$

#### HH.____: "Heaters"
- value = 1: Heaters are on
- value = 0: Heaters are off

#### SS.____: "Solenoids"
- value = 1: Solenoids are on (injected)
- value = 0: Solenoids are off (raised)

#### FF.____: "Fans"
- value = 1: Fans are on
- value = 2: Fans are off

## Error Codes (summary, see main README for more info on troubleshooting

### Type 1 Error: Invalid Entry
| Code  | Meaning                                       |
|-------|-----------------------------------------------|
| Er.11 | Invalid Desired Temperature, < 1 C or > 250 C |
| Er.12 | Invalid Heat Time, $\le$ 1 ms                 |
| Er.13 | Invalid Hold Time, $\le$ 1 ms                 |
| Er.14 | Invalid Cool Time, $\le$ 1 ms                 |

### Type 2 Error: Attempting to Input Data Without Serial Connection
| Code  | Meaning                     |
|-------|-----------------------------|
| Er.20 | Not connected to serial     |

### Type 3 Error: Overheating
| Code  | Meaning                          |
|-------|-----------------------------     |
| Er.31 | Barrel Overheating* (>300 C)     |
| Er.32 | Electronics Overheating (>100 C) |
| Er.33 | Invalid Hold Time (>150 C)       |

### Type 4 Error: Door Open (Gate sensor reading 1)
| Code  | Meaning     |
|-------|-------------|
| Er.31 | Gate 1 Open |
| Er.42 | Gate 2 Open |
