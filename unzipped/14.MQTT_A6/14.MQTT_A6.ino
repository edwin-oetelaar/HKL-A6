#include<WiFi.h>
#include<PubSubClient.h>
#include<PCF8574.h>

const char* ssid ="wx48";   // input your router's ssid
const char* password="a12345678";// input your router's password
const char* mqttServer ="192.168.50.88";// this is your MQTT server 
const int mqttPort=1883;
const char* mqttUsername="mqtt";  // this is your MQTT server username（Optional)
const char* mqttPassword="123"; // this is your MQTT server password（Optional)

PCF8574 pcf8574_out(0x24,4,15); // A6 sda is gpio4  scl is gpio15

WiFiClient espClient; // creat an instance
PubSubClient client(espClient);//creat an instance

void setup(){
    Serial.begin(1115200);
    Serial.println(__FILE__);// print the folder path
   String topic = "ESP32_A6/relay_control/command"; // creat the topic
   //  Initializes the WIFI 
  WiFi.begin(ssid,password);
  while(WiFi.status()!=WL_CONNECTED){
    delay(1000);
    Serial.println("wifi connecting....");
  }
    Serial.println("wifi connected");
  // Try to connect to MQTT SERVER
    client.setServer(mqttServer,mqttPort);
    client.setCallback(callback);
  while(!client.connected()){
      Serial.println("Connecting to MQTT...");
      if(client.connect("ESP32-A6",mqttUsername,mqttPassword)){
        Serial.println("MQTT Connected");
      }else {
        Serial.println("Check your MQTT settings");
        delay(2000);

      }
  }
  pcf8574_out.pinMode(P0,OUTPUT);
  pcf8574_out.pinMode(P1,OUTPUT);
  pcf8574_out.pinMode(P2,OUTPUT);
  pcf8574_out.pinMode(P3,OUTPUT);
  pcf8574_out.pinMode(P4,OUTPUT);
  pcf8574_out.pinMode(P5,OUTPUT);
  pcf8574_out.begin();
   
  Serial.println(topic.c_str());
  client.subscribe(topic.c_str());

}
void loop(){
    client.loop();
}
void callback(char* topic,byte* payload,int length) {
  Serial.println("Message arrived in topic:"+ String(topic));
  Serial.print("Payload is:");
  for(unsigned int i=0;i<length;i++) {
    Serial.write(payload[i]);
  }
  Serial.println();
  
  if(!strncmp((char*)payload,"{\"relay1\":\"on\"}",length)){
     pcf8574_out.digitalWrite(0,LOW);
  }
else if (!strncmp((char*)payload,"{\"relay1\":\"off\"}",length)){
  pcf8574_out.digitalWrite(0,HIGH);
}

if (!strncmp((char *)payload, "{\"relay2\":\"on\"}", length)) {
  pcf8574_out.digitalWrite(1,LOW);
}
else if (!strncmp((char *)payload, "{\"relay2\":\"off\"}", length)) {
  pcf8574_out.digitalWrite(1,HIGH);
  }
if (!strncmp((char *)payload, "{\"relay3\":\"on\"}", length)) {
  pcf8574_out.digitalWrite(2,LOW);
}
 else if (!strncmp((char *)payload, "{\"relay3\":\"off\"}", length)) {
  pcf8574_out.digitalWrite(2,HIGH);
 }
if (!strncmp((char *)payload, "{\"relay4\":\"on\"}", length)) {
  pcf8574_out.digitalWrite(3,LOW);
}
 else if (!strncmp((char *)payload, "{\"relay4\":\"off\"}", length)){
 pcf8574_out.digitalWrite(3,HIGH);
}
if (!strncmp((char *)payload, "{\"relay5\":\"on\"}", length)){
   pcf8574_out.digitalWrite(4,LOW);
}
 else if (!strncmp((char *)payload, "{\"relay5\":\"off\"}", length)) {
  pcf8574_out.digitalWrite(4,HIGH);
 }
if (!strncmp((char *)payload, "{\"relay6\":\"on\"}", length)) {
  pcf8574_out.digitalWrite(5,LOW);
  }
 else if (!strncmp((char *)payload, "{\"relay6\":\"off\"}", length)) {
  pcf8574_out.digitalWrite(5,HIGH); 
 }
if (!strncmp((char *)payload, "{\"relay\":\"on\"}", length)) {
  relay_on();
}
 else if (!strncmp((char *)payload, "{\"relay\":\"off\"}", length)) {
  relay_off(); }
}
void relay_on()
{
  Wire.beginTransmission(0x24);
  Wire.write(0x00); // set all output to LOW
  Wire.endTransmission(); 
}
void relay_off()
{
  Wire.beginTransmission(0x24);
  Wire.write(0x0ff); // set all output to HIGH
  Wire.endTransmission(); 
}

