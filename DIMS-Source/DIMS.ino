#include "DIMS.h"

//Global Object/Variable Defs

//Thermocouple Defs
MAX6675 thermocoupleBT1(CLK1, BT1CS, DO1);
MAX6675 thermocoupleBT2(CLK1, BT2CS, DO1);
MAX6675 thermocoupleET (CLK2, ETCS,  DO2);
MAX6675 thermocoupleMT (CLK2, MTCS,  DO2);

//Display Def
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

//Keypad Defs
char hexaKeys[ROWS][COLS] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '.', '0', '#', 'D' }
};
byte rowPins[ROWS] = { 46, 47, 48, 49 };
byte colPins[COLS] = { 50, 51, 52, 53 };
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

char         key          = 0;
int          entryComplete = 0;
const byte   MAX_CHARS    = 10;
char         inputBuffer[10];
byte         inputIndex   = 0;
float        floatTotal   = 0;
unsigned int intTotal     = 0;

//Paramter Setup
float currTemp    = 0;
float desiredTemp = 0;

float startTime = 0;
float currTime  = 0;
float heatTime  = 0;
float holdTime  = 0;
float coolTime  = 0;

int processStart = 0;

void setup() {
  Serial.begin(115200);

  //Display Setup
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  delay(2000);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("Welcome!");
  display.display();
  delay(2000);

  //Heater, Fan, Solenoid, Reed Sensor Setup
  digitalWrite(SOL, RAISE);
  digitalWrite(FAN, HIGH); //Start with fan on by default
  digitalWrite(HEATER, LOW);

  pinMode(HEATER, OUTPUT);
  pinMode(FAN,    OUTPUT);
  pinMode(SOL,    OUTPUT);
  pinMode(G1, INPUT_PULLUP);
  pinMode(G2, INPUT_PULLUP);

  Serial.println("FF.1");
  Serial.println("SS.0");
  Serial.println("HH.0");
  displayMenu();
}

void loop() {
  key = customKeypad.getKey(); //Check is keypad has been pressed

  if (millis() % 500 == 0) { //Every 500 ms, get data
    getData();
  }

  if (key == 'A') {  // Use computer to input parameters
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("Enter data on computer");
    display.display();
    while (true) {
      if (millis() % 500 == 0) { //Every 500 ms, get data
        getData();
      }

      while (Serial.available()) { //Check for data sent from computer
        String input = Serial.readStringUntil('\n');
        String index = input.substring(0, 3);
        String value = input.substring(3);
        if (index == "NT.") { //Set desired temperature
          desiredTemp = value.toFloat();
        } else if (index == "HT.") { //Set heat time
          heatTime = value.toFloat() * 60000;
        } else if (index == "WT.") { //Set hold time
          holdTime = value.toFloat() * 1000;
        } else if (index == "CT.") { //Set cool time
          coolTime = value.toFloat() * 60000;
        } else if (index == "S1.") { //Turn on/off solenoid
          digitalWrite(SOL, value == "1" ? LOWER : RAISE);
        } else if (index == "H1.") { //Turn on/off heater
          digitalWrite(HEATER, value == "1" ? HIGH : LOW);
        } else if (index == "F1.") { //Turn on/off fan
          digitalWrite(FAN, value == "1" ? HIGH : LOW);
          Serial.print("FF.");
          Serial.println(value);
        } else if (input == "PS.1") { //Start process
          processStart = 1;
        }
      }

      if (processStart > 0) {
        if (desiredTemp <= 1 || desiredTemp > 250 || heatTime <= 1 || holdTime <= 1 || coolTime <= 1) {
          display.clearDisplay();
          display.setCursor(0, 0);
          display.println("Settings are invalid\nReturning to menu");
          display.display();
          if (desiredTemp <= 1 || desiredTemp > 250) Serial.println("Er.11");
          if (heatTime <= 1) Serial.println("Er.12");
          if (holdTime <= 1) Serial.println("Er.13");
          if (coolTime <= 1) Serial.println("Er.14");
          processStart = 0;
          delay(2000);
          displayMenu();
        } else {
          processStart = 1;
          injectionProcess();
          displayMenu();
          break;
        }
      }
    }
  }

  if (key == 'B') {  // Set temperature and heat time via keypad
    desiredTemp = getDesiredTemp();
    heatTime    = getHeatTime();
    delay(2000);
    displayMenu();
  }

  if (key == 'C') {  // Set hold/cool times via keypad
    holdTime = getHoldTime();
    coolTime = getCoolTime();
    delay(2000);
    displayMenu();
  }

  if (key == 'D') {  // Begin process
    if (desiredTemp <= 1 || heatTime <= 1 || holdTime <= 1 || coolTime <= 1) {
      Serial.print(desiredTemp); Serial.print(",");
      Serial.print(heatTime);   Serial.print(",");
      Serial.print(holdTime);   Serial.print(",");
      Serial.println(coolTime);
      display.clearDisplay();
      display.setCursor(0, 0);
      display.println("Settings are invalid\nReturning to menu");
      display.display();
      delay(2000);
      displayMenu();
    } else {
      processStart = 1;
      injectionProcess();
      displayMenu();
    }
  }
}

//Other helper functions

void displayMenu() {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("A: Use Computer Data");
  display.println("B: Set Temperature");
  display.println("C: Set Timing");
  display.println("D: Begin Process");
  display.display();
}


void readKeypad() {
  key = customKeypad.getKey();

  if (key == '#') {
    floatTotal = atof(inputBuffer);
    Serial.println();
    Serial.println("entry is complete");
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print("Value Entered: ");
    display.println(floatTotal, 2);
    display.display();
    entryComplete = checkValue();

    if (entryComplete < 1) {
      floatTotal = 0;
      inputIndex = 0;
      Serial.println("Re-enter Value");
      display.clearDisplay();
      display.setCursor(0, 0);
      display.println("Re-enter Value");
      display.display();
    }
    if (entryComplete > 0) {
      return;
    }
  }
  if ((key >= '0' && key <= '9') || key == '.') {
    inputBuffer[inputIndex] = key;
    if (inputIndex != MAX_CHARS - 1) {
      inputIndex++;
    }
    inputBuffer[inputIndex] = '\0';
    Serial.println(inputBuffer);
    display.println(inputBuffer);
    display.display();
  }
}

float getDesiredTemp() {
  Serial.println("Enter Desired Temperature: ");
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Enter Desired Temp (C):");
  display.display();
  entryComplete = 0;
  while (entryComplete < 1) {
    readKeypad();
    if (entryComplete) {
      desiredTemp = floatTotal;
      Serial.print("Desired Temperature is ");
      Serial.print(desiredTemp, 2);
      Serial.println(" deg C");
      display.clearDisplay();
      display.setCursor(0, 0);
      display.print("Desired Temp: ");
      display.print(desiredTemp, 2);
      display.println("C");
      display.display();
      floatTotal = 0;
      inputIndex = 0;
    }
  }
  return desiredTemp;
}

float getHeatTime() {
  Serial.println("Enter Heat Time ");
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Enter Heat Time (min):");
  display.display();
  entryComplete = 0;
  while (entryComplete < 1) {
    readKeypad();
    if (entryComplete) {
      heatTime = floatTotal;
      Serial.print("Heat Time is ");
      Serial.print(heatTime, 2);
      Serial.println("min");
      display.clearDisplay();
      display.setCursor(0, 0);
      display.print("Heat Time: ");
      display.print(heatTime, 2);
      display.println("min");
      display.display();
      heatTime   = heatTime * 60000;
      floatTotal = 0;
      inputIndex = 0;
    }
  }
  return heatTime;
}

int checkValue() {
  Serial.println("Is value shown correct?\n Press A if correct\n Press B if not");
  display.println("Is value shown right?");
  display.println("Press A if correct");
  display.println("Press B if incorrect");
  display.display();
  while (true) {
    key = customKeypad.getKey();
    if (key == 'A') {
      return 1;
    }
    if (key == 'B') {
      return 0;
    }
  }
}

float getHoldTime() {
  Serial.println("Enter Hold Time ");
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Enter Hold Time (s):");
  display.display();
  entryComplete = 0;
  while (entryComplete < 1) {
    readKeypad();
    if (entryComplete) {
      holdTime = floatTotal;
      Serial.print("Hold Time is ");
      Serial.print(holdTime, 2);
      Serial.println("s");
      display.clearDisplay();
      display.setCursor(0, 0);
      display.print("Hold Time: ");
      display.print(holdTime, 2);
      display.println("s");
      display.display();
      holdTime   = holdTime * 1000;
      floatTotal = 0;
      inputIndex = 0;
    }
  }
  return holdTime;
}

float getCoolTime() {
  Serial.println("Enter Cool Time ");
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Enter Cool Time (min):");
  display.display();
  entryComplete = 0;
  while (entryComplete < 1) {
    readKeypad();
    if (entryComplete) {
      coolTime = floatTotal;
      Serial.print("Cool Time is ");
      Serial.print(coolTime, 2);
      Serial.println("min");
      display.clearDisplay();
      display.setCursor(0, 0);
      display.print("Cool Time: ");
      display.print(coolTime, 2);
      display.println("min");
      display.display();
      coolTime   = coolTime * 60000;
      floatTotal = 0;
      inputIndex = 0;
    }
  }
  return coolTime;
}
