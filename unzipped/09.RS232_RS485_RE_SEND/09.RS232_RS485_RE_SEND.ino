/*HANKERILA_MODEL:A6 code of RS485 and RS232 
HANKERILA CONTROLLER STORE : https://www.aliexpress.com/store/1103673574
*/
void setup() {

  Serial1.begin(9600,SERIAL_8N1,16,17);  //  IO16   232RX   IO17 232TX
  Serial2.begin(9600,SERIAL_8N1,14,27);  //  IO14   485RX   IO27 485TX
  Serial1.println("USB TO RS232 send is OK"); // RS232 port output the string
  Serial2.println("USB TO RS485 send is OK"); // RS485 port output the string

}

void loop() {

  /*if Serial1(RS232) receive data ,print it*/
  while(Serial1.available()>0)
   {
    //Read rs232 receive data  and print it
    Serial1.print((char)Serial1.read());
   }
  delay(200);
  /*if Serial2(RS485) receive data ,print it*/
  while(Serial2.available()>0)
   {
    Serial2.print((char)Serial2.read());//Read rs485 receive data  and print it
   }
  delay(200);
}
