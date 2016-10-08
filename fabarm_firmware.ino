#include <Servo.h> 

const int potpin0 = A0;
const int potpin1 = A1;
const int potpin2 = A2;
const int potpin3 = A3;

Servo servo0, servo1, servo2, servo3;
 
void setup() 
{ 
  Serial.begin(9600);
  pinMode(potpin0, INPUT);
  pinMode(potpin1, INPUT);
  pinMode(potpin2, INPUT);
  pinMode(potpin3, INPUT);
  servo0.attach(3);
  servo1.attach(5);
  servo2.attach(6);
  servo3.attach(9);
} 
 
void loop() 
{
  int value;

  value = analogRead(potpin0);
  value = map(value, 0, 1023, 0, 179);
  servo0.write(value);
  Serial.println(value);

  value = analogRead(potpin1);
  value = map(value, 0, 1023, 40, 120);
  servo1.write(value);
  Serial.println(value);

  value = analogRead(potpin2);
  value = map(value, 0, 1023, 0, 179);
  servo2.write(value);
  Serial.println(value);

  value = analogRead(potpin3);
  value = map(value, 0, 1023, 0, 179);
  servo3.write(value);
  Serial.println(value);

  delay(100);
}
