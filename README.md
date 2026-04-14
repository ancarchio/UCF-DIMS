## Linktree: https://linktr.ee/UCF_DIMS


## To Use:
**READ THE FULL MANUAL BEFORE USE**
>[!NOTE]
>The DIMS Application is currently only available on Windows
1. Download the latest version of DIMS.exe and install
2. Turn on the machine
3. Plug the USB cord from the machine into the computer
4. Open the DIMS application
5. Under "Serial Connection", choose the COM port that the machine is attached to
6. Click connect
7. Data (temperatures, gate readings, relay states) should appear under "Current Data"
8. Input parameters under "Setup"
9. Ensure mold is properly placed and doors are closed
10. Click "Begin Injection" when ready
11. Once the process is complete and the mold is sufficiently cooled, remove from the machine

## Error Codes and Troubleshooting
### Type 1 Error: Invalid Entry
| Code  | Meaning                                       |
|-------|-----------------------------------------------|
| Er.11 | Invalid Desired Temperature, < 1 C or > 250 C |
| Er.12 | Invalid Heat Time, $\le$ 1 ms                 |
| Er.13 | Invalid Hold Time, $\le$ 1 ms                 |
| Er.14 | Invalid Cool Time, $\le$ 1 ms                 |

#### To Resolve:
* Check inputted parameters. Ensure all are above zero, and that the desired temperature is also below 250 C

### Type 2 Error: Attempting to Input Data Without Serial Connection
| Code  | Meaning                     |
|-------|-----------------------------|
| Er.20 | Not connected to serial     |

>[!WARNING]
>Unplugging the machine from the computer without hitting "Disconnect" first will cause the application to crash instead of giving an error

#### To Resolve:
* Ensure machine is properly connected to your computer via the USB cable
* Ensure correct COM port is selected
  * If you cannot find the correct COM port, go to your Device Manager under COM Ports.\
    Unplug, then replugin the USB cable. Determine which COM appeared
  * If the COM still does not appear, refresh the application
  * If the machine does not appear in the Device Manager
    1. Restart Machine
    2. Turn off machine and check that the cord is plugged into the Arduino, unplug and replugin the cord
    3. The cord may be broken and require replacement
    4. If issues still persist, there is likely an issue with the Arduino itself

>[!NOTE]
>If a Type 3 or Type 4 Error occurs during an injection cycle, the heaters will be turned off and the solenoids will be deactivated\
>An error message will persist on the screen until the issue is resolved\
>Once the issue is resolved, the screen will return to the menu, and the cycle will not continue.\
>A purge cycle may need to be run before running another injection cycle.

### Type 3 Error: Overheating
| Code  | Meaning                          |
|-------|-----------------------------     |
| Er.31 | Barrel Overheating* (>300 C)     |
| Er.32 | Electronics Overheating (>100 C) |
| Er.33 | Invalid Hold Time (>150 C)       |

*"Barrel Overheating" counts if at least one barrel thermocouple is reading over 300 C, not just the average

>[!WARNING]
>**DO NOT OPEN THE MACHINE WHILE IT IS OVERHEATING!** Do not risk burning yourself or exposing yourself to fumes!\
>If you receive this error, immediately stop the injection process. You may leave the machine on, so the fans run.\
>Do not continue the injection process until the temperatures are back within safe values

#### To Resolve:
* Wait and allow the machine to cool down, following all safety protocols
  * If the overheat was genuine, ensure all functions are working properly. Inspect circuits for problems. Test machine before using again.
* If the temperature displayed is much higher than could be possible (ex. >1000 C), is switching between NaN, 0, and extremely high values,\
  Or, is much higher than the other temperatures (eg. BT1 is showing 30 C while BT2 is showing 350) There is likely an issue with at least one thermocouple.
  1. Make note of which thermocouple is reading incorrectly
  2. Disconnect the machine from the computer, turn off the machine, then unplug the machine
  3. Wait for the machine to cool down, especially if a cycle was run recently (wait at least 30 mins after the last cycle)
  4. Verify the thermocouple is not grounded (ie. not touching any metal parts that may be connected to the circuit)
     * All thermocouples have high-temp electric tape on/under them to prevent this. The tape may need to be replaced.
     * <ins>**Be extremely cautious when opening the insulation on the barrel to perform maintenance**</ins>
  5. Verify the connections of the thermocouple to the amplifiers and the amplifiers to the Arduino are secure
     * Tighten the screws on the amplifiers
     * Connections between the amplifiers and Arduino may need to be redone or reinforced
  6. If the issue persists, the thermocouple and/or amplifier may require replacement.

### Type 4 Error: Door Open (Gate sensor reading 1)
| Code  | Meaning     |
|-------|-------------|
| Er.31 | Gate 1 Open |
| Er.42 | Gate 2 Open |

>[!WARNING]
>NEVER OPEN THE MACHINE DURING PROCESSING!\
>There is a great injury risk due to the heat and pressure within the system.\
>If the process needs to be stopped at any time, use the E-Stop, then wait for the machine to cool down before opening it up

#### To Resolve:
* Close doors immediately
* If the error occurred while all the doors are closed, there may be an issue with the magnetic reed sensors:
  1. Make a note of which sensor failed (can be checked without running a cycle, under the Current Data section)
  2. Wait for the machine to cool down, turn it off, and unplug it
  3. Ensure the magnetic reed sensor and the associated magnet are in their correct positions
  4. Verify the connections of the sensor to the Arduino are secure
  5. If issues persist, the sensor may require replacement

>[!NOTE]
>All connections and input/output 
