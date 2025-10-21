/*
  Auto Exhaust E-Fan
  -------------------
  Arduino-based automatic exhaust fan that controls fan speed
  according to room temperature using the LM35 temperature sensor.

  Components:
  - Arduino Uno
  - LM35 Temperature Sensor
  - 12V DC Fan (or 5V DC for testing)
  - 16x2 LCD (I2C interface recommended)
  - Transistor (2N2222 or BC547)
  - Resistor 1K
  - Diode 1N4007
  - Power Supply (9V–12V)
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize the LCD (I2C address 0x27 may vary)
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int tempPin = A0;    // LM35 output pin
const int fanPin  = 9;     // PWM pin controlling fan transistor

// Temperature thresholds (in °C)
const float tempMin = 25.0;  // Fan off below this temperature
const float tempMax = 40.0;  // Fan full speed above this temperature

float temperature = 0.0;
int fanPWM = 0;
int fanSpeedPercent = 0;

void setup() {
  pinMode(fanPin, OUTPUT);
  lcd.init();        // Initialize the LCD
  lcd.backlight();   // Turn on LCD backlight

  lcd.setCursor(0, 0);
  lcd.print("Auto Exhaust Fan");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Read temperature from LM35 (10mV/°C)
  int sensorValue = analogRead(tempPin);
  temperature = (sensorValue * 5.0 * 100.0) / 1024.0;

  // Determine fan speed based on temperature
  if (temperature < tempMin) {
    fanPWM = 0;
  } else if (temperature > tempMax) {
    fanPWM = 255;
  } else {
    fanPWM = map(temperature, tempMin, tempMax, 100, 255);
  }

  analogWrite(fanPin, fanPWM);
  fanSpeedPercent = map(fanPWM, 0, 255, 0, 100);

  // Display temperature and fan speed on LCD
  lcd.setCursor(0, 0);
  lcd.print("Temp:");
  lcd.print(temperature, 1);
  lcd.print((char)223);
  lcd.print("C   ");

  lcd.setCursor(0, 1);
  lcd.print("Fan:");
  lcd.print(fanSpeedPercent);
  lcd.print("%    ");

  delay(1000);
}
