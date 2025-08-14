#include <Wire.h>
#include <RTClib.h>

// Define the RTC_DS1307 object
RTC_DS1307 rtc;

void setup() {
    Serial.begin(9600);  // Initialize serial communication with a baud rate of 9600
    Serial.println(__FILE__);  // Print the current file path
    Wire.begin(4, 15);   // Start I2C communication, SDA is GPIO4, SCL is GPIO15

    if (!rtc.begin()) {  // If unable to initialize the RTC
        Serial.println("Couldn't find RTC");  // Print message that RTC can't be found
        while (1);  // Enter an infinite loop
    }

    if (!rtc.isrunning()) {  // If the RTC is not running
        Serial.println("RTC is not running!");  // Print message that RTC is not running
        rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));  // Adjust the RTC according to the compile time
    //rtc.adjust(DateTime(2024,4,28,9,30,30));
    }

    // Uncomment the next line when uploading the code for the first time to set the initial time
    // rtc.adjust(DateTime(2024, 3, 29, 20, 5, 30));
    //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
}

void loop() {
    DateTime now = rtc.now();  // Get the current time from the RTC

    // Print the date and time
    Serial.print("The time is: ");
    Serial.print(now.year());  // Print the year
    Serial.print("-");
    printDigits(now.month());  // Print the month with formatting
    Serial.print("-");
    printDigits(now.day());  // Print the day with formatting
    Serial.print("-");
    printDigits(now.hour());  // Print the hour with formatting
    Serial.print("-");
    printDigits(now.minute());  // Print the minute with formatting
    Serial.print("-");
    printDigits(now.second());  // Print the second with formatting
    Serial.println();

    delay(1000);  // Delay for 1 second
}

void printDigits(int digits) {
    if (digits < 10) {  // If the digit is less than 10
        Serial.print("0");  // Print a leading "0"
    }
    Serial.print(digits);  // Print the digit
}