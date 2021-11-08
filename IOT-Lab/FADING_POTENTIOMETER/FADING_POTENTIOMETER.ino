int analogIN = 0;
int analogOUT = 11;
int s_value = 0;
int output_value = 0;

void setup() {
  pinMode(analogOUT,OUTPUT);
  pinMode(analogIN,INPUT);
  Serial.begin(9600);
}

void loop() {
  s_value = analogRead(analogIN);
  output_value = map(s_value,0 ,1023,0,255);
  analogWrite(analogOUT,output_value);
  Serial.println("Sensor value = ");
  Serial.println(s_value);
  Serial.println("output value = ");
  Serial.println(output_value);
  delay(10);

}
