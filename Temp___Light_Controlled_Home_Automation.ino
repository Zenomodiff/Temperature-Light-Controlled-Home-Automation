/*feel free to contact
 * sreeramaj53@gmail.com
 * www.youtube.com/ZenoModiff
 * last updated - time 11:51am - date 12 may 2021
 */

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include "DHT.h"
#define DHTPIN 7
#define DHTTYPE DHT11

int Light = 4 ;
int Fan = 5 ;
const int ldrPin = 6;
LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(DHTPIN, DHTTYPE);

void setup()
{
 
  Serial.begin(9600);
  Serial.println(F("Home - Automation With DHT22 - LDR "));
  
  dht.begin();

  lcd.begin();
  lcd.setCursor(0,0);
  lcd.print("Home");
  lcd.setCursor(0,3);
  lcd.print("Automation");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("With");
  lcd.setCursor(0,3);
  lcd.print("LDR - DHT22");
  delay(2000);
  lcd.clear();
  lcd.print("By");
  lcd.setCursor(0,3);
  lcd.print("Zeno Modiff");
  delay (3000);
  lcd.clear();
  
  pinMode(Light , OUTPUT);
  pinMode(Fan , OUTPUT);
  pinMode(ldrPin , INPUT);
  
}

void loop()
{
  
 float t = dht.readTemperature();
 float f = dht.readTemperature(true);
 
 if (isnan(t) || isnan(f)) {
 Serial.println(F("Failed to read from DHT sensor!"));
 return;
}

 Serial.print("DHT-Temp: ");Serial.print(t);Serial.println(" c");
  
int Ldr_Status = digitalRead(ldrPin);  
if (Ldr_Status > 0)

{

digitalWrite(Light, LOW);

Serial.print("Its DARK, Turn on the LED : ");
lcd.clear();
lcd.print("Light Turned ON");
lcd.setCursor(0,3);
lcd.print("Temp: ");
lcd.setCursor(6,7);
lcd.println(t);
delay(1000);

Serial.println(Ldr_Status);

}
else 
{

digitalWrite(Light, HIGH);

Serial.print("Its DARK, Turn on the LED : ");

lcd.clear();
lcd.print("Light Turned OFF");
lcd.setCursor(0,3);
lcd.print("Temp: ");
lcd.setCursor(6,7);
lcd.println(t);
delay(2000);

Serial.print("Its BRIGHT, Turn off the LED : ");

Serial.println(Ldr_Status);

}
 if(t>34){          
    digitalWrite(Fan, LOW);   
    lcd.clear();
    lcd.print("Fan Turned ON");
    delay(2000);
   
    
  }
  else 
  digitalWrite(Fan , HIGH);
      lcd.clear();
      lcd.print("Fan Turned OFF");
      delay(1000);
}
