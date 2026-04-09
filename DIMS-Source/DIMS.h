#ifndef DIMS_H
#define DIMS_H

#include <Arduino.h>
#include <Keypad.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <EduIntro.h>
#include <max6675.h>

// Pin Definitions

// Thermocouple pins
#define CLK   38
#define DO    39
#define BT1CS 40
#define BT2CS 41
#define ETCS  42
#define MTCS  43

// Gate Sensor pins
#define G1 22
#define G2 23

// Misc. Pins
#define FAN    30
#define HEATER 29
#define SOL    28

// OLED dimensions
#define SCREEN_WIDTH  128
#define SCREEN_HEIGHT  64

// Keypad dimensions
const byte ROWS = 4;
const byte COLS = 4;

// Object/Variable Definitions

extern MAX6675 thermocoupleBT1;
extern MAX6675 thermocoupleBT2;
extern MAX6675 thermocoupleET;
extern MAX6675 thermocoupleMT;

extern Adafruit_SSD1306 display;

extern Keypad customKeypad;

extern char key;
extern int  entryComplete;
extern const byte MAX_CHARS;
extern char  inputBuffer[];
extern byte  inputIndex;
extern float floatTotal;
extern unsigned int intTotal;

// Temp
extern float currTemp;
extern float desiredTemp;

// Timing
extern float startTime;
extern float currTime;
extern float heatTime;
extern float holdTime;
extern float coolTime;

// Process Start
extern int processStart;

// Function Declaration
void displayMenu();
void getData();
void readKeypad();
float getDesiredTemp();
float getHeatTime();
int   checkValue();
float getHoldTime();
float getCoolTime();
void  injectionProcess();

#endif // DIMS_H
