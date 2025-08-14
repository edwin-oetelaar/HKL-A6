/*HANKERILA A6 The second way to read the  digital input */

#include "Arduino.h"
#include "PCF8574.h"

#define SDA 4
#define SCL 15

PCF8574 pcf8574_IN1(0x22,SDA,SCL);

void setup()
{
  Serial.begin(115200);
  Wire.begin(SDA,SCL);
  
  for(int i=0;i<=7;i++){
    pcf8574_IN1.pinMode(i,INPUT);
  }  
   
    pcf8574_IN1.begin();
    pcf8574_write1(word(B11111111));
}
void loop()
{  
   for(int i=0;i<6;i++){
    if(pcf8574_IN1.digitalRead(i)==0) {
      delay(200);
        if(pcf8574_IN1.digitalRead(i)==0) { 
      Serial.printf("INPUT %d  is triggered\n",i+1);
    }  
   }
   }
 delay(100);
}

void  pcf8574_write1(uint8_t data) 
{
  Wire.beginTransmission(0x22);
  Wire.write(data);
  Wire.endTransmission();
}