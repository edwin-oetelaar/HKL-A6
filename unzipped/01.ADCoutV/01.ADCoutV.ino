/*ESP32_A6 arduino code of ADC
 Board is:NodeMCU-32S
 Hardware defined pin
 ANALOG_A1   36
 ANALOG_A2   39
 ANALOG_A3   34
 ANALOG_A4   35
*/
#include "Arduino.h"
#define ANALOG_A1   36  // Define analog input pin A1 as 36
#define ANALOG_A2   39  // Define analog input pin A2 as 39
#define ANALOG_A3   34  // Define analog input pin A3 as 34
#define ANALOG_A4   35  // Define analog input pin A4 as 35

void setup() {
  Serial.begin(9600);       // Start serial communication at 9600 baud rate
  Serial.println(__FILE__); // Print the source file path
}

void loop() {
  int V1 = analogRead(ANALOG_A1);      // Read analog value from pin A1 and store in V1
  int V2 = analogRead(ANALOG_A2);      // Read analog value from pin A2 and store in V2
  int V3 = analogRead(ANALOG_A3);      // Read analog value from pin A3 and store in V3
  int V4 = analogRead(ANALOG_A4);      // Read analog value from pin A4 and store in V4
  //Voltage data is read from port A1 into the just-created integer variable V1 
  //The voltage measurement range of the analog port is 0-5V and the value returned is 0-4095
  float vol = V1*(5.0 / 4095.0);    // Convert the analog value V1 to voltage
  float vo2 = V2*(5.0 / 4095.0);    // Convert the analog value V2 to voltage
  float vo3 = V3*(5.0 / 4095.0);    // Convert the analog value V3 to voltage
  float vo4 = V4*(5.0 / 4095.0);    // Convert the analog value V4 to voltage
  // Any set of analog interface data changes will print 4 sets of data
  if (V1 > 0 || V2 > 0 || V3 > 0 || V4 > 0) {
    Serial.printf("The voltage of ADC_01 is:%.2fV\n", vol);   // Print the voltage of ADC_01
    Serial.printf("The voltage of ADC_02 is:%.2fV\n", vo2);   // Print the voltage of ADC_02
    Serial.printf("The voltage of ADC_03 is:%.2fV\n", vo3);   // Print the voltage of ADC_03
    Serial.printf("The voltage of ADC_04 is:%.2fV\n", vo4);   // Print the voltage of ADC_04
    Serial.println();
    delay(1000);
  }
}