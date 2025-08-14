/*A6 code of DAC output*/

#define DAC1 26
#define DAC2 25

void setup() {
  Serial.begin(9600);
  Serial.println(__FILE__);  //Print file storage path
}

void loop() { 
 /*
 int Value = 127; //255= 10V
  
  dacWrite(DAC1, 255);
  delay(500);
  dacWrite(DAC2, 255);
  delay(500);
  dacWrite(DAC1, 0);
  delay(500);
  dacWrite(DAC2, 0);
  delay(500);*/
/*PWM output control led strip*/
  for(int i=0;i<=255;i++)
  {
    dacWrite(DAC1,i);
    delay(50);
    dacWrite(DAC2,i);
    delay(50);
  }
  for(int i=255;i>=0;i--)
  {
    dacWrite(DAC1,i);
    delay(50);
    dacWrite(DAC2,i);
    delay(50);
  }

}
