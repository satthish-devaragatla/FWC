#include <Arduino.h>
int D1,q0,q1,q2;
void setup()
{
pinMode(13, OUTPUT);
pinMode(2, INPUT);
pinMode(3, INPUT);
pinMode(4, INPUT);
}
void loop(){
  q2 = digitalRead(2);
q1 = digitalRead(3);
q0 = digitalRead(4);
D1= ((!q2&&q0)||(q1&&!q0));
digitalWrite(13, D1);
}
