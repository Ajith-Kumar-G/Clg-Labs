void setup() {
 pinMode(11,OUTPUT);
}

void loop() {
  int i;
  for(i = 0; i < 256; i++){
    analogWrite(11,i);
    delay(20);
  }
  for(i = 255; i > -1; i--){
    analogWrite(11,i);
    delay(20);
  }
}
