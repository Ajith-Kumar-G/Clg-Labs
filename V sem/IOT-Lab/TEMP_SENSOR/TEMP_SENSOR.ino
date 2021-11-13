//REQ: Arduino, BB, TempSensor
float celsius;

void setup() {
Serial.begin(9600);
pinMode(A0, INPUT);
}

void loop() {
float rawVolt = analogRead(A0);
float milliVolt = (rawVolt * 5000) / 1024;
celsius = milliVolt / 10;
Serial.print(" In Celsius: ");
Serial.println(celsius);
Serial.print(" In Fahrenheit: ");
Serial.println((celsius * 9/5) +32);
delay(1000);
}
