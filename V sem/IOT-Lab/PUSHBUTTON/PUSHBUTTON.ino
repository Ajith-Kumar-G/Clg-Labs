const int inputPin = 2;
const int outputPin = 13;
int count = 0;

void setup() {
  pinMode(13,OUTPUT);
  pinMode(2,INPUT);
  Serial.begin(9600);
}

void loop() {
  int value = digitalRead(inputPin);
  if(value == 1){
    digitalWrite(outputPin, HIGH);
    count ++;
    Serial.println(count);  
  }
  else
  digitalWrite(outputPin,LOW);
  delay(100);
}
