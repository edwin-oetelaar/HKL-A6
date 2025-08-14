/*A6 OLED SSD1306 Code  */

#include <U8g2lib.h>
#include <Wire.h>


U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0,  15, 4, U8X8_PIN_NONE);//SCL IO15  SDA  IO4  
void page1() {

  u8g2.setFont(u8g2_font_timR12_tf);//Font 12
  u8g2.setCursor(0,30);  //X Y position
  u8g2.print("Hankerila:A6"); //display words
 }
void setup(){

  u8g2.setI2CAddress(0x3C*2);  // address
  u8g2.begin();
  u8g2.enableUTF8Print();
}
void loop(){

  u8g2.firstPage();
  do
  {
    page1();
  }while(u8g2.nextPage());

}
