/*A6 PCF8574 output control relays*/

#include "Arduino.h"
#include "PCF8574.h"

// Create an instance of A6 
// Set the i2c address
PCF8574 pcf8574(0x24,4,15);
// Create an instance of DO8 
// Set the i2c address
PCF8574 pcf8574_8(0x20,4,15);

void setup()
{
	Serial.begin(9600);
  Serial.println(__FILE__);  //Print file storage path

	// Set pinMode to OUTPUT
	pcf8574.pinMode(P0, OUTPUT);
  pcf8574.pinMode(P1, OUTPUT);
  pcf8574.pinMode(P2, OUTPUT);
  pcf8574.pinMode(P3, OUTPUT);
  pcf8574.pinMode(P4, OUTPUT);
  pcf8574.pinMode(P5, OUTPUT);

  pcf8574_8.pinMode(P0, OUTPUT);
  pcf8574_8.pinMode(P1, OUTPUT);
  pcf8574_8.pinMode(P2, OUTPUT);
  pcf8574_8.pinMode(P3, OUTPUT);
  pcf8574_8.pinMode(P4, OUTPUT);
  pcf8574_8.pinMode(P5, OUTPUT);
  pcf8574_8.pinMode(P6, OUTPUT);
  pcf8574_8.pinMode(P7, OUTPUT);

  pcf8574.begin();
  pcf8574_8.begin();

}

void loop()
{
  for(int i=0;i<=5;i++)
  {
    delay(300);
	  pcf8574.digitalWrite(i, LOW);
  }
  for(int i=0;i<=7;i++)
  {
    delay(300);
	  pcf8574_8.digitalWrite(i, LOW);
  }
  for(int i=0;i<=5;i++)
  {
    delay(300);
	  pcf8574.digitalWrite(i, HIGH);
  }
   for(int i=0;i<=7;i++)
  {
    delay(300);
	  pcf8574_8.digitalWrite(i, HIGH);
  }/*
	delay(300);
	pcf8574.digitalWrite(P0, LOW);
  delay(300);
  pcf8574.digitalWrite(P1, LOW);
  delay(300);
  pcf8574.digitalWrite(P2, LOW);
  delay(300);
  pcf8574.digitalWrite(P3, LOW);
  delay(300);
  pcf8574.digitalWrite(P4, LOW);
  delay(300);
  pcf8574.digitalWrite(P5, LOW);
  delay(300);
  delay(300);
	pcf8574.digitalWrite(P0, HIGH);
  delay(300);
  pcf8574.digitalWrite(P1, HIGH);
  delay(300);
  pcf8574.digitalWrite(P2, HIGH);
  delay(300);
  pcf8574.digitalWrite(P3, HIGH);
  delay(300);
  pcf8574.digitalWrite(P4, HIGH);
  delay(300);
  pcf8574.digitalWrite(P5, HIGH);
  delay(300);*/
}
