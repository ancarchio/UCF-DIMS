#ifndef DIMS_H
#define DIMS_H

#include <Arduino.h>
#include <Keypad.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <EduIntro.h>
#include <max6675.h>

//Thermocouple Setup
#define CLK 38
#define DO 39
#define BT1CS 40
#define BT2CS 41
#define ETCS 42
#define MTCS 43

extern char key;
extern int entryComplete;
extern const byte MAX_CHARS;
extern byte inputIndex;
extern float floatTotal;
extern unsigned int intTotal;

//Temp Setup
extern float currTemp;
extern float desiredTemp;

//Timing Setup
extern float startTime;
extern float currTime;
extern float heatTime;
extern float holdTime;
extern float coolTime;

//Process Start Setup
extern int processStart;

//Gate Sensor Setup
#define G1 22
#define G2 23

//Fan Setup
#define FAN 30

//Heater Setup
#define HEATER 29

//Solenoid Setup
#define SOL 28



//Function Declaration
void displayMenu();
void getData();
void readKeypad();
float getDesiredTemp();
float getHeatTime();
int checkValue();
float getHoldTime();
float getCoolTime();
void injectionProcess();

#endif