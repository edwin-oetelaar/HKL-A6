/*A6 code of DAC output*/

#define DAC1 26  // Define DAC output pin 1 as 26
#define DAC2 25  // Define DAC output pin 2 as 25

void setup() {
    Serial.begin(9600);  // Initialize serial communication with a baud rate of 9600
    Serial.println(__FILE__);  // Print the file storage path
}

void loop() { 
    int Value = 255;  // Define a value as 255
    dacWrite(DAC1, Value);  // Write the value to DAC1 pin
    delay(500);  // Delay for 500 milliseconds
    dacWrite(DAC2, Value);  // Write the value to DAC2 pin
    delay(500);  // Delay for 500 milliseconds
}