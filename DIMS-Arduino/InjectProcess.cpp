#include "DIMS.h"
#include <Arduino.h>

void injectionProcess() {
  getData();
  digitalWrite(FAN, HIGH); //Fans are always on during processing
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Beginning process \n Heating Plastic to ");
  display.print(desiredTemp, 2);
  display.println("F");
  display.print("For");
  display.print(heatTime / 1000, 2);
  display.print("seconds");
  display.display();
  Serial.println("IP.1");
  startTime = millis();
  currTime = millis();
  while (startTime + heatTime > currTime) {  //Heat so outer temp == input for heatTime seconds
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
    display.println((currTime - startTime) / 1000, 2);
    display.print("Of ");
    display.print(heatTime / 1000, 2);
    display.print("s");
    display.display();
    Serial.print("PT.");
    Serial.println(100 * (currTime - startTime) / heatTime);
    delay(250);
    currTime = millis();
  }
  getData();
  digitalWrite(HEATER, LOW);
  Serial.println("HH.0");
  Serial.println("IP.2");
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Injecting");
  display.display();
  delay(1000);
  digitalWrite(SOL, HIGH);  //Activate pneumatics
  //digitalWrite(SR, HIGH);
  Serial.println("SL.1");
  Serial.println("SR.1");
  startTime = millis();
  currTime = millis();
  while (startTime + holdTime > currTime) {  //Hold with pressure
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
  digitalWrite(SOL, LOW);  //Deactivate pneumatics
  //digitalWrite(SR, LOW);
  Serial.println("IP.3");
  Serial.println("SL.0");
  Serial.println("SR.0");
  startTime = millis();
  currTime = millis();
  while (startTime + coolTime > currTime) {  //Cool without pressure
    getData();
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print("Cooling for ");
    display.print(coolTime / 1000, 2);
    display.println("s");
    display.print("Current Time: ");
    display.print((currTime - startTime) / 1000, 2);
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