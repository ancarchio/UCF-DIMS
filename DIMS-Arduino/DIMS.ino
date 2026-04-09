#include "DIMS.h"
//#include "InjectProcess.cpp"
//OLED Setup
#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

//Keypad Setup
const byte ROWS = 4;
const byte COLS = 4;
char hexaKeys[ROWS][COLS] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '.', '0', '#', 'D' }
};
byte rowPins[ROWS] = { 46, 47, 48, 49 };  //Pins ordered star-D
byte colPins[COLS] = { 50, 51, 52, 53 };
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
char key;
int entryComplete = 0;
const byte MAX_CHARS = 10;
char inputBuffer[MAX_CHARS];
byte inputIndex = 0;
float floatTotal = 0;
unsigned int intTotal;

//Temp Setup
float currTemp = 0;
float desiredTemp = 0;

//Timing Setup
float startTime = 0;
float currTime = 0;
float heatTime = 0;
float holdTime = 0;
float coolTime = 0;

//Process Start Setup
int processStart = 0;


MAX6675 thermocoupleBT1(CLK, BT1CS, DO);
MAX6675 thermocoupleBT2(CLK, BT2CS, DO);
MAX6675 thermocoupleET(CLK, ETCS, DO);
MAX6675 thermocoupleMT(CLK, MTCS, DO);


void setup() {
  Serial.begin(115200);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {  // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;
  }
  delay(2000);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  // Display static text
  display.println("Welcome!");
  display.display();
  delay(2000);
  displayMenu();

  pinMode(HEATER, OUTPUT);    //Heater Relay
  pinMode(FAN, OUTPUT);       //Fan Relay
  pinMode(SOL, OUTPUT);       //Solenoid Relays
                              // pinMode(SR, OUTPUT);
  pinMode(G1, INPUT_PULLUP);  //Gate Sensors
  pinMode(G2, INPUT_PULLUP);

  digitalWrite(FAN, HIGH);
}

void loop() {

  key = customKeypad.getKey();

  if (millis() % 500 == 0) {
    getData();
  }

  if (key == 'A') {  //If user selects A, they will use the computer to input paramters
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("Enter data on computer");
    display.display();
    while (true) {
      if (millis() % 500 == 0) {
        getData();
      }

      while (Serial.available()) {
        String input = Serial.readStringUntil('\n');
        String index = input.substring(0, 3);
        String value = input.substring(3);
        if (index == "NT.") {
          desiredTemp = value.toFloat();
          Serial.println(desiredTemp);
          Serial.println(processStart);
        }
        if (index == "HT.") {
          heatTime = value.toFloat() * 1000;
        } else if (index == "WT.") {
          holdTime = value.toFloat() * 1000;
        } else if (index == "CT.") {
          coolTime = value.toFloat() * 1000;
        } else if (index == "S1.") {
          if (value == "1") {
            digitalWrite(SOL, HIGH);
          }
          if (value == "0") {
            digitalWrite(SOL, LOW);
          }
        } else if (index == "H1.") {
          if (value == "1") {
            digitalWrite(HEATER, HIGH);
          }
          if (value == "0") {
            digitalWrite(HEATER, LOW);
          }
        } else if (index == "F1.") {
          if (value == "1") {
            digitalWrite(FAN, HIGH);
          }
          if (value == "0") {
            digitalWrite(FAN, LOW);
          }
        } else if (input == "PS.1") {
          processStart = 1;
        }
      }
      if (processStart > 0) {
        if (desiredTemp <= 1 || heatTime <= 1 || holdTime <= 1 || coolTime <= 1) {
          display.clearDisplay();
          display.setCursor(0, 0);
          display.println("Settings are invalid \nReturning to menu");
          display.display();
          if (desiredTemp <= 1 || desiredTemp > 250){
            Serial.println("Er.11");
          }
          if (heatTime <= 1){
            Serial.println("Er.12");
          }
          if (holdTime <= 1){
            Serial.println("Er.13");
          }
          if (coolTime <= 1){
            Serial.println("Er.14");
          }
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

  if (key == 'B') {  //If user selects B, initiate function to get temp for injection
    desiredTemp = getDesiredTemp();
    heatTime = getHeatTime();
    delay(2000);
    displayMenu();
  }

  if (key == 'C') {  //If user selects C, initiate function to get timing
    holdTime = getHoldTime();
    coolTime = getCoolTime();
    delay(2000);
    displayMenu();
  }

  if (key == 'D') {  //If user selects D, initiate main program
    if (desiredTemp <= 1 || heatTime <= 1 || holdTime <= 1 || coolTime <= 1) {
      Serial.print(desiredTemp);
      Serial.print(",");
      Serial.print(heatTime);
      Serial.print(",");
      Serial.print(holdTime);
      Serial.print(",");
      Serial.println(coolTime);
      display.clearDisplay();
      display.setCursor(0, 0);
      display.println("Settings are invalid \nReturning to menu");
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

void displayMenu() {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("A: Use Computer Data");
  display.println("B: Set Temperature");
  display.println("C: Set Timing");
  display.println("D: Begin Process");
  display.display();
}

void getData() {
  float tempBarrel1 = thermocoupleBT1.readCelsius();
  float tempBarrel2 = thermocoupleBT2.readCelsius();
  float electronicsTemp = thermocoupleET.readCelsius();
  float moldTemp = thermocoupleMT.readCelsius();
  int gate1 = digitalRead(G1);
  int gate2 = digitalRead(G2);
  if (electronicsTemp > 100 || moldTemp > 150 || tempBarrel1 > 300 || tempBarrel2 > 300) {
    digitalWrite(HEATER, LOW);
    digitalWrite(SOL, LOW);
    //digitalWrite(SR, LOW);
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("Overheating");
    display.println("Allow machine to cool down");
    display.display();
    if (tempBarrel1 > 300 || tempBarrel2 > 300){
      Serial.println("Er.31");
    }
    if (electronicsTemp > 100){
      Serial.println("Er.32");
    }
    if (moldTemp > 150){
      Serial.println("Er.33");
    }
    delay(2000);
    processStart = 0;
    while (electronicsTemp > 100 || moldTemp > 150 || tempBarrel1 > 300 || tempBarrel2 > 300) {
      tempBarrel1 = thermocoupleBT1.readCelsius();
      tempBarrel2 = thermocoupleBT2.readCelsius();
      electronicsTemp = thermocoupleET.readCelsius();
      moldTemp = thermocoupleMT.readCelsius();
      Serial.print("T1.");
      Serial.println(tempBarrel1, 2);
      Serial.print("T2.");
      Serial.println(tempBarrel2, 2);
      Serial.print("T3.");
      Serial.println(electronicsTemp, 2);
      Serial.print("T4.");
      Serial.println(moldTemp, 2);
      delay(2000);
    }
  }
  if ((gate1 != 0 || gate2 != 0) && processStart == 1) {
    digitalWrite(HEATER, LOW);
    digitalWrite(SOL, LOW);
    //digitalWrite(SR, LOW);
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("Do Not Open Door");
    display.println("During Processing");
    display.display();
    delay(2000);
    processStart = 0;
    while (gate1 != 0 || gate2 != 0) {
      gate1 = digitalRead(G1);
      gate2 = digitalRead(G2);
      Serial.print("G1.");
      Serial.println(gate1);
      Serial.print("G2.");
      Serial.println(gate2);
      delay(500);
    }
  }
  Serial.print("T1.");
  Serial.println(tempBarrel1, 2);
  Serial.print("T2.");
  Serial.println(tempBarrel2, 2);
  Serial.print("T3.");
  Serial.println(electronicsTemp, 2);
  Serial.print("T4.");
  Serial.println(moldTemp, 2);
  Serial.print("G1.");
  Serial.println(gate1);
  Serial.print("G2.");
  Serial.println(gate2);
}

void readKeypad() {
  key = customKeypad.getKey();

  if (key == '#')  //user signal that entry has finished
  {
    floatTotal = atof(inputBuffer);  //convert buffer to a float
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
      return;  //exit the function
    }
  }
  if (key >= '0' && key <= '9' || key == '.')  //only act on numeric or '.' keys
  {
    inputBuffer[inputIndex] = key;  //put the key value in the buffer
    if (inputIndex != MAX_CHARS - 1) {
      inputIndex++;  //increment the array
    }
    inputBuffer[inputIndex] = '\0';  //terminate the string
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
  while (entryComplete < 1) {  //will be checked after reading a key
    readKeypad();              //get a key if available
    if (entryComplete)         //number entry is complete
    {
      desiredTemp = floatTotal;
      Serial.print("Desired Temperature is ");
      Serial.print(desiredTemp, 2);
      Serial.println(" deg C");
      display.clearDisplay();
      display.setCursor(0, 0);
      display.print("Desired Temp: ");
      display.print(desiredTemp, 2);
      display.println("F");
      display.display();
      floatTotal = 0;  //reset the total
      inputIndex = 0;  //and the index to the input buffer
    }
  }
  return desiredTemp;
}

float getHeatTime() {
  Serial.println("Enter Heat Time ");
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Enter Heat Time (s):");
  display.display();
  entryComplete = 0;
  while (entryComplete < 1) {  //will be checked after reading a key
    readKeypad();              //get a key if available
    if (entryComplete)         //number entry is complete
    {
      heatTime = floatTotal;
      Serial.print("Heat Time is ");
      Serial.print(heatTime, 2);
      Serial.println("s");
      display.clearDisplay();
      display.setCursor(0, 0);
      display.print("Heat Time: ");
      display.print(heatTime, 2);
      display.println("s");
      display.display();
      heatTime = heatTime * 1000;  //Convert to milliseconds
      floatTotal = 0;              //reset the total
      inputIndex = 0;              //and the index to the input buffer
    }
  }

  return heatTime;
}

int checkValue() {
  Serial.println("Is value shown correct? \n Press A if correct \n Press B if not");
  display.println("Is value shown right?");
  display.println("Press A if correct");
  display.println("Press B if incorrect");
  display.display();
  while (entryComplete < 1) {
    key = customKeypad.getKey();
    if (key == 'A') {
      entryComplete = 1;
      return entryComplete;
    }
    if (key == 'B') {
      entryComplete = 0;
      return entryComplete;
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
  while (entryComplete < 1) {  //will be checked after reading a key
    readKeypad();              //get a key if available
    if (entryComplete)         //number entry is complete
    {
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
      holdTime = holdTime * 1000;  //Convert to milliseconds
      floatTotal = 0;              //reset the total
      inputIndex = 0;              //and the index to the input buffer
    }
  }
  return holdTime;
}

float getCoolTime() {
  Serial.println("Enter Cool Time ");
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Enter Cool Time (s):");
  display.display();
  entryComplete = 0;
  while (entryComplete < 1) {  //will be checked after reading a key
    readKeypad();              //get a key if available
    if (entryComplete)         //number entry is complete
    {
      coolTime = floatTotal;
      Serial.print("Cool Time is ");
      Serial.print(coolTime, 2);
      Serial.println("s");
      display.clearDisplay();
      display.setCursor(0, 0);
      display.print("Cool Time: ");
      display.print(coolTime, 2);
      display.println("s");
      display.display();
      coolTime = coolTime * 1000;  //Convert to milliseconds
      floatTotal = 0;              //reset the total
      inputIndex = 0;              //and the index to the input buffer
    }
  }
  return coolTime;
}


