#include "DIMS.h"
#include <Arduino.h>

//Function to run injection
void injectionProcess() {
  getData();
  digitalWrite(FAN, HIGH); //Fans are always on during processing
  Serial.println("FF.1");
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Beginning process \n Heating Plastic to ");
  display.print(desiredTemp, 2);
  display.println("C");
  display.print("For");
  display.print(heatTime / 60000, 2);
  display.print("seconds");
  display.display();
  Serial.println("IP.1");
  startTime = millis();
  currTime = millis();
  while (startTime + heatTime > currTime && processStart == 1) {  //Heat so outer temp == input for heatTime seconds
    getData();
    currTemp = (thermocoupleBT1.readCelsius() + thermocoupleBT2.readCelsius()) / 2;
    if (currTemp < desiredTemp) {
      digitalWrite(HEATER, HIGH);
      Serial.println("HH.1");
    } else {
      digitalWrite(HEATER, LOW);
      Serial.println("HH.0");
    }
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print("Desired Temp: ");
    display.print(desiredTemp, 2);
    display.println("C");
    display.print("Current Temp: ");
    display.println(currTemp, 2);
    display.print("Current Time: ");
    display.println((currTime - startTime) / 60000, 2);
    display.print("Of ");
    display.print(heatTime / 60000, 2);
    display.print("min");
    display.display();
    Serial.print("PT.");
    Serial.println(100 * (currTime - startTime) / heatTime);
    delay(250);
    currTime = millis();
  }
  getData();
  if (processStart == 0) return; //Do not continue if there was an error
  digitalWrite(HEATER, LOW);
  Serial.println("HH.0");
  Serial.println("IP.2");
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Injecting");
  display.display();
  delay(1000);
  digitalWrite(SOL, LOWER);  //Activate pneumatics
  Serial.println("SS.1");
  startTime = millis();
  currTime = millis();
  while (startTime + holdTime > currTime && processStart == 1) {  //Hold with pressure
    getData();
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print("Holding for ");
    display.print(holdTime / 1000, 2);
    display.println("s");
    display.print("Current Time: ");
    display.print((currTime - startTime) / 1000, 2);
    display.display();
    Serial.print("PT.");
    Serial.println(100 * (currTime - startTime) / holdTime);
    currTime = millis();
  }
  getData();
  if (processStart == 0) return; //Do not continue if there was an error
  digitalWrite(SOL, RAISE);  //Deactivate pneumatics
  Serial.println("IP.3");
  Serial.println("SS.0");
  startTime = millis();
  currTime = millis();
  while (startTime + coolTime > currTime && processStart == 1) {  //Cool without pressure
    getData();
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print("Cooling for ");
    display.print(coolTime / 60000, 2);
    display.println("min");
    display.print("Current Time: ");
    display.print((currTime - startTime) / 60000, 2);
    display.display();
    Serial.print("PT.");
    Serial.println(100 * (currTime - startTime) / coolTime);
    currTime = millis();
  }
  Serial.println("IP.4");
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Process complete\nCarefully remove mold");
  display.display();
  processStart = 0;
  delay(5000);
  displayMenu();
}

void getData() {

  //Check Temperatures
  float tempBarrel1 = thermocoupleBT1.readCelsius();
  float tempBarrel2 = thermocoupleBT2.readCelsius();
  float electronicsTemp = thermocoupleET.readCelsius();
  float moldTemp = thermocoupleMT.readCelsius();

  //Check reed sensors
  int gate1 = digitalRead(G1);
  int gate2 = digitalRead(G2);

  //Check for overheating
  if (electronicsTemp > 100 || moldTemp > 150 || tempBarrel1 > 300 || tempBarrel2 > 300) {
    digitalWrite(HEATER, LOW); //Turn off heaters
    digitalWrite(SOL,    RAISE); //Set solenoids to not injected
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("Overheating");
    display.println("Allow machine to cool down");
    display.display();
    //Send errors to computer
    if (tempBarrel1 > 300 || tempBarrel2 > 300) Serial.println("Er.31");
    if (electronicsTemp > 100)                  Serial.println("Er.32");
    if (moldTemp > 150)                         Serial.println("Er.33");
    delay(2000);
    processStart = 0; //Stop processing
    //Wait for temperatures to be back to normal
    while (electronicsTemp > 100 || moldTemp > 150 || tempBarrel1 > 300 || tempBarrel2 > 300) {
      tempBarrel1 = thermocoupleBT1.readCelsius();
      tempBarrel2 = thermocoupleBT2.readCelsius();
      electronicsTemp = thermocoupleET.readCelsius();
      moldTemp = thermocoupleMT.readCelsius();
      Serial.print("T1."); Serial.println(tempBarrel1, 2);
      Serial.print("T2."); Serial.println(tempBarrel2, 2);
      Serial.print("T3."); Serial.println(electronicsTemp, 2);
      Serial.print("T4."); Serial.println(moldTemp, 2);
      delay(2000);
    }
  }

  //Check for open door (during injection only)
  if ((gate1 != 0 || gate2 != 0) && processStart == 1) {
    digitalWrite(HEATER, LOW); //Turn off heaters
    digitalWrite(SOL,    RAISE); //Set solenoids to not injected
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("Do Not Open Door");
    display.println("During Processing");
    display.display();
    delay(2000);
    processStart = 0; //Stop processing
    //Send errors
    if (gate1 != 0) Serial.println("Er.41");
    if (gate2 != 0) Serial.println("Er.42");
    //Wait for door to close
    while (gate1 != 0 || gate2 != 0) {
      gate1 = digitalRead(G1);
      gate2 = digitalRead(G2);
      Serial.print("G1."); Serial.println(gate1);
      Serial.print("G2."); Serial.println(gate2);
      delay(500);
    }
  }

  //Send data to computer
  Serial.print("T1."); Serial.println(tempBarrel1, 2);
  Serial.print("T2."); Serial.println(tempBarrel2, 2);
  Serial.print("T3."); Serial.println(electronicsTemp, 2);
  Serial.print("T4."); Serial.println(moldTemp, 2);
  Serial.print("G1."); Serial.println(gate1);
  Serial.print("G2."); Serial.println(gate2);
}