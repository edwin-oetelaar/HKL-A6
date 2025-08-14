/*
 Analog port 36 39 34 35 to measure voltage
*/
#include "Arduino.h"
float temp1;   //Create a floating point variable temp1 as a storage space to store data
float temp2;   //Create a floating point variable temp2 as a storage space to store data
float temp3;   //Create a floating point variable temp3 as a storage space to store data
float temp4;   //Create a floating point variable temp4 as a storage space to store data
#define ANALOG_A1   36
#define ANALOG_A2   39
#define ANALOG_A3   34
#define ANALOG_A4   35
void setup()
{
  Serial.begin(9600);     
  Serial.println(__FILE__);// Print file storage path
}
void loop()
{
  //Creates a variable to read the value of the simulated interface
  int V1 = analogRead(ANALOG_A1);      
  int V2 = analogRead(ANALOG_A2); 
  int V3 = analogRead(ANALOG_A3); 
  int V4 = analogRead(ANALOG_A4); 

  delay(1000);        
/*The voltage data is read from the analog port and stored in the just-created integer variable Vo1/Vo2/Vo3/Vo4
 The voltage measurement range of the analog port is 0-5V and the value returned is 0-4095*/
  float vo1 = V1*(5.0 / 4095.0);    
  float vo2 = V2*(5.0 / 4095.0); 
  float vo3 = V3*(5.0 / 4095.0); 
  float vo4 = V4*(5.0 / 4095.0);   
/*Output the data when the voltage value is changed    */     
 if (vo1 == temp1)                             
    
        {
          temp1 = vo1;      //store the value to temp1
        }
  else
        { 
          Serial.printf("Voltage_01 is %.2fV \n",vo1);        
          temp1 = vo1;
          delay(1000);                           
        }

  if (vo2 == temp2)                             
        {
          temp2 = vo2;                               
        }
  else
        { 
          Serial.printf("Voltage_02 is %.2fV \n",vo2);                        
          temp2 = vo2;
          delay(1000);                           
        }

  if (vo3 == temp3)                             

        {
          temp3 = vo3;                             
        }
  else
        { 
          Serial.printf("Voltage_03 is %.2fV \n",vo3);                     
          temp3 = vo3;
          delay(1000);                           
        }

  if (vo4 == temp4)                             
        {
          temp4 = vo4;                               
        }
  else
        { 
          Serial.printf("Voltage_04 is %.2fV \n",vo4);                  
          temp4 = vo4;
          delay(1000);                           
        }

  
}
