#include <Servo.h> 

const int potpin0 = A0,
          potpin1 = A1,
          potpin2 = A2,
          potpin3 = A3;

const int dpotvalueThreshold0 = 50,
          dpotvalueThreshold1 = 50,
          dpotvalueThreshold2 = 50,
          dpotvalueThreshold3 = 50;

const int dpotvalueMin0 = -50,
          dpotvalueMin1 = -50,
          dpotvalueMin2 = -50,
          dpotvalueMin3 = -50;

const int dpotvalueMax0 = 50,
          dpotvalueMax1 = 50,
          dpotvalueMax2 = 50,
          dpotvalueMax3 = 50;

int potvalue0,
    potvalue1,
    potvalue2,
    potvalue3;

int angle0,
    angle1,
    angle2,
    angle3;

const int angleMin0 = 0,
          angleMin1 = 40,
          angleMin2 = 0,
          angleMin3 = 0;

const int angleMax0 = 179,
          angleMax1 = 120,
          angleMax2 = 179,
          angleMax3 = 179;

const int angleMiddle0 = (angleMax0 + angleMin0) / 2,
          angleMiddle1 = (angleMax1 + angleMin1) / 2,
          angleMiddle2 = (angleMax2 + angleMin2) / 2,
          angleMiddle3 = (angleMax3 + angleMin3) / 2;

const int angleSpeedMax0 = 2,
          angleSpeedMax1 = 2,
          angleSpeedMax2 = 2,
          angleSpeedMax3 = 8;

Servo servo0,
      servo1,
      servo2,
      servo3;
 
void setup() 
{
  pinMode(potpin0, INPUT);
  pinMode(potpin1, INPUT);
  pinMode(potpin2, INPUT);
  pinMode(potpin3, INPUT);

  servo0.attach(3);
  servo1.attach(5);
  servo2.attach(6);
  servo3.attach(9);

  potvalue0 = analogRead(potpin0);
  potvalue1 = analogRead(potpin1);
  potvalue2 = analogRead(potpin2);
  potvalue3 = analogRead(potpin3);

  angle0 = angleMiddle0;
  angle1 = angleMiddle1;
  angle2 = angleMiddle2;
  angle3 = angleMiddle3;
}

void loop() 
{
  int potvalue;
  float dpotvalue;
  float kangleSpeed0;

  potvalue = analogRead(potpin0);
  dpotvalue = potvalue0 - potvalue;
  if(abs(dpotvalue) > dpotvalueThreshold0) {
    if(dpotvalue > 0)
      kangleSpeed0 = min(dpotvalue, dpotvalueMax0) / dpotvalueMax0;
    else
      kangleSpeed0 = -1 * max(dpotvalue, dpotvalueMin0) / dpotvalueMin0;
    angle0 += kangleSpeed0 * angleSpeedMax0;
    angle0 = constrain(angle0, angleMin0, angleMax0);
  }
  servo0.write(angle0);

  potvalue = analogRead(potpin1);
  dpotvalue = potvalue1 - potvalue;
  if(abs(dpotvalue) > dpotvalueThreshold1) {
    if(dpotvalue > 0)
      kangleSpeed0 = min(dpotvalue, dpotvalueMax1) / dpotvalueMax1;
    else
      kangleSpeed0 = -1 * max(dpotvalue, dpotvalueMin1) / dpotvalueMin1;
    angle1 += kangleSpeed0 * angleSpeedMax1;
    angle1 = constrain(angle1, angleMin1, angleMax1);
  }
  servo1.write(angle1);

  potvalue = analogRead(potpin2);
  dpotvalue = potvalue2 - potvalue;
  if(abs(dpotvalue) > dpotvalueThreshold2) {
    if(dpotvalue > 0)
      kangleSpeed0 = min(dpotvalue, dpotvalueMax2) / dpotvalueMax2;
    else
      kangleSpeed0 = -1 * max(dpotvalue, dpotvalueMin2) / dpotvalueMin2;
    angle2 += kangleSpeed0 * angleSpeedMax2;
    angle2 = constrain(angle2, angleMin2, angleMax2);
  }
  servo2.write(angle2);

  potvalue = analogRead(potpin3);
  dpotvalue = potvalue3 - potvalue;
  if(abs(dpotvalue) > dpotvalueThreshold3) {
    if(dpotvalue > 0)
      kangleSpeed0 = min(dpotvalue, dpotvalueMax3) / dpotvalueMax3;
    else
      kangleSpeed0 = -1 * max(dpotvalue, dpotvalueMin3) / dpotvalueMin3;
    angle3 += kangleSpeed0 * angleSpeedMax3;
    angle3 = constrain(angle3, angleMin3, angleMax3);
  }
  servo3.write(angle3);

  delay(10);
}
