int calibrationTime = 30;
long unsigned int pause = 5000, temp=0;
bool lowLock = false, highLock =true,reCheck=true;
int pirPin = 3; //the digital pin connected to the PIR sensor&#39;s output
int ledPin = 13;

void setup(){
Serial.begin(9600);
pinMode(pirPin, INPUT);
pinMode(ledPin, OUTPUT);
Serial.print("calibrating sensor ");
  
for(int i = 0; i < calibrationTime; i++){
Serial.print(".");
delay(1000);
}
  
Serial.println(" done");
Serial.println("SENSOR ACTIVE");
delay(50);
}

void loop(){
  
if(digitalRead(pirPin) == HIGH ){
digitalWrite(ledPin, HIGH);
  if(highLock){
  Serial.println("---");
  Serial.print("motion detected at ");
  Serial.print(millis()/1000);
  Serial.println(" sec");
  delay(50);
    lowLock=true;
    highLock=false;
  }
  reCheck=true;
}
  
if(digitalRead(pirPin) == LOW && lowLock){

  if(reCheck){
  temp=millis();
    reCheck=false;
  }
  if(millis() - temp > pause){
    digitalWrite(ledPin, LOW);
  Serial.print("motion ended at "); 
  Serial.print((millis() - pause)/1000);
  Serial.println(" sec");
  delay(50);
  lowLock=false;
    highLock=true;
  }
}
}
