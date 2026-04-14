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
- value = 1: Turns on solenoids
- value = 0: Turns off solenoids

#### F1.____: "Fans"
- value = 1: Turns on fans
- value = 2: Turns off fans
