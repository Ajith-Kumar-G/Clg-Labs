//REQ: Arduini, BB, LDR, Resistor, LED

int limit = 100;
int outpin  = 9;

void setup() {
  pinMode(A0,INPUT);
  pinMode(9,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  int input = analogRead(A0);
  //Serial.println(input);
  if (input < limit)
 {
  digitalWrite(outpin,HIGH);
 }
 else
 {
  digitalWrite(outpin,LOW);
 }
 
  delay(1000);
}
