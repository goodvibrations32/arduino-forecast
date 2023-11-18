#include <Adafruit_AHTX0.h>
#include <Arduino.h>
#include <stdio.h>
#include <LiquidCrystal.h>

const int rs=12, en=11, d4=5, d5=4, d6=3, d7=2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

Adafruit_AHTX0 aht;

void setup(){
  lcd.begin(16, 2);
  Serial.begin(9600);

  if (! aht.begin()){
    Serial.println("Could not find AHT?? Check wiring ?@!");
    while(1) delay(10);
  }
  Serial.println("AHT10 not found...");
  /* pinMode(13, OUTPUT); */
}

void loop(){
  sensors_event_t humidity, temp;
  aht.getEvent(&humidity, &temp);
  // when characters arrive over the serial port...
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(temp.temperature);
  lcd.print(" ");
  lcd.print((char)223);
  lcd.print("C!");

  lcd.setCursor(0, 0);
  lcd.print("Hum:  ");
  lcd.print(humidity.relative_humidity);
  lcd.print(" %rH!");

  /* lcd.print("Hum: %d %rH", humidity.relative_humidity); */

  delay(500);

}
