#include "SoftwareSerial.h"
 
#define WIFISSID "IOT5A"      // WIFI Username
#define WIFIPASS ""         // WIFI Password
 
SoftwareSerial Serial1(2,3);

void read_write()
{ 
while (Serial1.available())
{
char c = Serial1.read();
Serial.write(c);
if(c=='\r') Serial.print('\n');
}
Serial.print('\n');
delay(2000);
Serial1.flush();

}

void setupAP() {
  String Cmd = "AT+CWSAP=\"";
  Cmd+=WIFISSID;  Cmd+="\",\""; Cmd+=WIFIPASS; Cmd+="\",8,0";
  Serial1.println(Cmd);
  delay(1000);

   read_write();
}
 
// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  pinMode(12,OUTPUT);
 
  // Setup Wifi as AP
  Serial1.println("AT+CWMODE=2");
  delay(1000);

   read_write();
   
  setupAP();

  //Set as multiple connection mode
  Serial1.println("AT+CIPMUX=1");
  delay(1000);
   read_write();
   
 // Configure server
  Serial1.println("AT+CIPSERVER=1");
  delay(1000);
   read_write();

}

void loop() {
  
  if(Serial1.available())
  {
   String message = Serial1.readString();
   Serial.println (message);
    if(message.indexOf("SWITCH ON")>0)
    {
      digitalWrite(12,HIGH);
    }
    else if(message.indexOf("SWITCH OFF")>0)
    {
      digitalWrite(12,LOW);
    }
    else
    {
      Serial.println ("Nothing to do...");
    }
  }
}
