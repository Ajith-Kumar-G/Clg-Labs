
int redLed = 8, greenLed = 9, blueLed = 5;
void setup() {
   
  pinMode(redLed,OUTPUT); 
  pinMode(greenLed,OUTPUT); 
  pinMode(blueLed,OUTPUT);

}

void loop() {
  
 digitalWrite(greenLed,LOW);
 digitalWrite(blueLed,LOW);
 digitalWrite(redLed,LOW);
 delay(2000);
 digitalWrite(redLed,HIGH);

}
