#include "DHT.h"
#include <LiquidCrystal.h>
#define dht_1 2
#define DHTTYPE DHT22
int Contrast=75;
LiquidCrystal lcd(12, 11, 7, 5, 4, 3);

DHT dht(dht_1, DHTTYPE);
int FAN = 13;
void setup() {
  pinMode(FAN, OUTPUT);
  pinMode(8, OUTPUT);
  Serial.begin(9600);
  analogWrite(6,Contrast);
  lcd.begin(16, 2);
  dht.begin();
}

void loop() {
  delay(250);

  float humid = dht.readHumidity();
  float temp = dht.readTemperature();
  if (humid <= 60)digitalWrite(FAN, LOW);
  if (humid > 60)digitalWrite(FAN, HIGH);
  if (temp < 30) digitalWrite(8, HIGH);
  if (temp >= 30) digitalWrite(8, LOW);
  lcd.setCursor(0, 0);
  lcd.print("Humidity : ");
  lcd.print(humid);
  lcd.setCursor(0, 1);
  lcd.print("Temp : ");
  lcd.print(temp);
//  Serial.println("Humidity : ");
//  Serial.println(humid);
//  Serial.println("Temperature : ");
//  Serial.println(temp);
//  Serial.println("Degree centigrade : ");
}
