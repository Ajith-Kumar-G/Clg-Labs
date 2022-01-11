#include<SoftwareSerial.h>

SoftwareSerial mySerial(6,7);

#define LEDPIN 13
char tag[] ="53002913C4AD"; // Replace with your own Tag ID
char input[12];        // A variable to store the Tag ID being presented
int count = 0;        // A counter variable to navigate through the input[] character array
boolean flag = true;     // A variable to store the Tag match status
void setup()
{
  Serial.begin(9600);   // Initialise Serial Communication with the Serial Monitor
  mySerial.begin(9600);
  pinMode(LEDPIN,OUTPUT); //WRONG TAG INDICATOR
}
void loop()
{
  String id;
  if(mySerial.available())
  {
     id = mySerial.readString();
     Serial.println(id) ;
     flag = true;
    } 
  if (flag && id.equals("5300292DD087")){
  Serial.println("Access Allowed");
  flag = false;
  }
  else if (flag)
  Serial.println("Denied ");
  flag = false;
}
