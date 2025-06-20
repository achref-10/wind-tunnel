#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "HX711.h"
 
// LCD Setup
LiquidCrystal_I2C lcd(0x27, 16, 2);
 
// HX711 Load Cells
HX711 scaleLift;
HX711 scaleDrag;
 
// HX711 Pins
#define DT_LIFT 2
#define SCK_LIFT 3
#define DT_DRAG 4
#define SCK_DRAG 5
 
// IR Sensor Pin
#define IR_SENSOR 6
 
// Fan Control
#define FAN_PIN 7
 
// Constants
float carWeight = 0.085 * 9.81; // in Newton
float airDensity = 1.225;
float surfaceArea = 0.01; // m²
 
// Variables
unsigned long lastIRTime = 0;
int rpmCount = 0;
float fanRPM = 0;
float fanSpeed = 0; // km/h
float airSpeed = 0; // km/h
float lift = 0, drag = 0;
float Cl = 0, Cd = 0;
 
void rpmInterrupt() {
  rpmCount++;
}
 
void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  
  pinMode(FAN_PIN, OUTPUT);
  digitalWrite(FAN_PIN, LOW);
 
  pinMode(IR_SENSOR, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(IR_SENSOR), rpmInterrupt, FALLING);
 
  scaleLift.begin(DT_LIFT, SCK_LIFT);
  scaleDrag.begin(DT_DRAG, SCK_DRAG);
 
  scaleLift.set_scale(); // Calibrate later
  scaleLift.tare();
  scaleDrag.set_scale(); // Calibrate later
  scaleDrag.tare();
 
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" WIND TUNNEL ");
}
 
void loop() {
  if (Serial.available()) {
    char cmd = Serial.read();
    
    if (cmd == 's') {
      lcd.clear();
      lcd.print("Starting...");
      delay(10000); // wait for fan plug-in
 
      digitalWrite(FAN_PIN, HIGH);
      rpmCount = 0;
      delay(5000); // measure for 5 seconds
 
      detachInterrupt(digitalPinToInterrupt(IR_SENSOR));
      fanRPM = (rpmCount / 2.0) * 60.0 / 5.0; // Assuming 2 pulses/rev
      fanSpeed = (fanRPM * 0.10472 * 0.3) * 3.6; // Assuming fan radius 15cm → 0.3m diameter
      airSpeed = fanSpeed * 0.2;
 
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Fan: ");
      lcd.print(fanSpeed, 1);
      lcd.print("km/h");
      lcd.setCursor(0, 1);
      lcd.print("Air: ");
      lcd.print(airSpeed, 1);
      lcd.print("km/h");
      delay(10000);
    }
 
    if (cmd == 'd') {
      lcd.clear();
      lcd.print("PUT THE CAR");
      delay(3000);
 
      lift = scaleLift.get_units(10);
      drag = scaleDrag.get_units(10);
 
      float V = airSpeed / 3.6; // convert to m/s
 
      Cl = (2 * lift) / (airDensity * V * V * surfaceArea);
      Cd = (2 * drag) / (airDensity * V * V * surfaceArea);
 
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Cl:");
      lcd.print(Cl, 2);
      lcd.setCursor(8, 0);
      lcd.print("Cd:");
      lcd.print(Cd, 2);
 
      Serial.print("LIFT:");
      Serial.println(lift);
      Serial.print("DRAG:");
      Serial.println(drag);
      Serial.print("CL:");
      Serial.println(Cl);
      Serial.print("CD:");
      Serial.println(Cd);
    }
 
    if (cmd == 'a') {
      // send data for MATLAB analysis
      Serial.println("MATLAB_MODE");
    }
  }
}