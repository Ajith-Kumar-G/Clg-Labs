const int inputPin = 2;
const int outputPin = 13;

void setup() {
  pinMode(13,OUTPUT);
  pinMode(2,INPUT);
}

void loop() {
  int value = digitalRead(inputPin);
  if(value == 1){
    digitalWrite(outputPin, HIGH);
  }
  else
  digitalWrite(outputPin,LOW);
  delay(100);
}
