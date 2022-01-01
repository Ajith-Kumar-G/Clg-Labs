#include<SoftwareSerial.h>
#define WIFISSID "IOT5A"     // WIFI Username
#define WIFIPASS ""             // WIFI Password
#define SERVERIP "192.168.4.1"  // WIFI Server
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

 void connectToServer() {

  String cmd = "AT+CIPSTART=\"TCP\",\"";
cmd += SERVERIP;
cmd += "\",\"330\"";
Serial1.println(cmd);
Serial.println(cmd);
if(Serial1.find("Error")) return;
 }
 // the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);

  while(!Serial); 
  while(!Serial1);

 while(Serial1.available()>0)
     Serial1.read();
 
  // Setup Wifi as STA and connect to AP
  Serial1.println("AT+CWMODE=1");
  Serial.println("AT+CWMODE=1");
  delay(1000);

   read_write();
 
  //connect to wifi

String cmd="AT+CWJAP=\"";
cmd+=WIFISSID;
cmd+="\",\"";
cmd+=WIFIPASS;
cmd+="\"";
Serial1.println(cmd);
Serial.println(cmd);
delay(2000);

read_write();

// Setup as single connection mode
  Serial1.println("AT+CIPMUX=0");
  delay(1000);
   read_write();
}
 
// the loop function runs over and over again forever
void loop() {
  if (Serial.available()) {
    String text = Serial.readString();
    connectToServer();
    char cipsend[100];
    sprintf (cipsend, "AT+CIPSEND=%d",text.length());
   
   Serial1.println(cipsend);
    if(Serial1.find(">"))
    {
      Serial.print(">");
    }
    else
    {
      Serial1.println("AT+CIPCLOSE");
      Serial.println("connect timeout");
      delay(1000);
      return;
    }
Serial1.print(text.c_str());
delay(2000);
read_write();

}
}
