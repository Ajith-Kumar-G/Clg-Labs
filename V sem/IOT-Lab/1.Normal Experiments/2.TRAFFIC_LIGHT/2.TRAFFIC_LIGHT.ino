const int r=13, y=12, g=11;

void setup() {
  pinMode(r,OUTPUT);
  pinMode(y,OUTPUT);
  pinMode(g,OUTPUT);
}

void loop() {
    changeLights();
}

void changeLights(){
   digitalWrite(r,HIGH);
    delay(5000);
    digitalWrite(r,LOW);
    digitalWrite(y,HIGH);
    delay(3000);
    digitalWrite(y,LOW);
    digitalWrite(g,HIGH);
    delay(7000);
    digitalWrite(g,LOW);
}
