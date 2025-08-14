/*A6 PCF8574 output control relays*/

#include "Arduino.h"
/*install pcf8574 library*/
#include "PCF8574.h"


/*SDA pin GPIO4*/
/*SCL pin GPIO15*/
#define SDA 4
#define SCL 15
/*Create the PCF8574 instance*/
/*Set i2c address*/
PCF8574 pcf8574(0x24,SDA,SCL);



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
  //Initialize PCF8574
  pcf8574.begin();
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
  delay(300);
}

void loop()
{
 /* delay(300);
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
