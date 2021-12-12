#include<SoftwareSerial.h>
SoftwareSerial BT(6,7);

void setup() {
  Serial.begin(9600);
  Serial.print("Enter AT Command: ");
  BT.begin(38400);
}

void loop() {
  if (BT.available())
  Serial.write(BT.read());

  if (Serial.available())
  BT.write(Serial.read());
}
