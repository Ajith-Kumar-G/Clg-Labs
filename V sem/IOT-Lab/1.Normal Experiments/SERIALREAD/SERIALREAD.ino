const int outP = 13;
char input;
void setup() {
  pinMode(outP,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(Serial.available() ){
     input = Serial.read();
    }
   if (input == 'A'){
   digitalWrite(outP,HIGH);
   delay(1000);
   }
   else
   digitalWrite(outP,LOW);
}
