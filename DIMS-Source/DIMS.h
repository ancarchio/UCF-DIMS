#ifndef DIMS_H
#define DIMS_H

#include <Arduino.h>
#include <Keypad.h>
#include <Wire.h>
//#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
//#include <EduIntro.h>
#include <max6675.h>

// Pin Definitions

// Thermocouple pins
#define CLK1  36 // Barrel CLK, Purple/Blue
#define DO1   37 // Barrel DO, Green/Brown
#define CLK2  39 // ET/MT CLK
#define DO2   38 // ET/MT DO
#define BT1CS 34 // Orange
#define BT2CS 29 // Yellow
#define ETCS  42 //
#define MTCS  43 //

// Gate Sensor pins
#define G1 24 //Blue
#define G2 25 //Orange

// Misc. Pins
#define FAN    33 //Green, relay IN2
#define HEATER 28 //White
#define SOL    32 //Yellow, relay IN1
#define RAISE HIGH //When relay is high, raise plunger
#define LOWER LOW //When relay is low, inject plunger

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
