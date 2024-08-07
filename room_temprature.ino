#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define Pin_Sensor A0

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

void loop() {
  int value = analogRead(Pin_Sensor);
  float voltage = value * (5.0 / 1024.0);
  float temprature = voltage * 100;

  Serial.print("Temperature: ");
  lcd.setCursor(0, 0);
  lcd.print("Temprature:");
  lcd.setCursor(0, 1);
  temprature /= 2;
  Serial.println(temprature);
  temprature = round(temprature);
  lcd.print(temprature);
  lcd.setCursor(6, 1);
  lcd.print("C");

  delay(2500);
}
