#include <Servo.h>

#define FRAC 10

Servo mot1;

int p = 0;
int pOld = 0;

int deg;

void setup()
{
  Serial.begin(9600);
  mot1.attach(7, 1000, 2000);
}

void loop()
{
  p = pulseIn(12, HIGH);
  pOld = (int) (((FRAC-1)*pOld + p)/FRAC);
  deg = map(pOld, 1200, 1800, 0, 15);
  Serial.println(deg);
  mot1.write(deg);
}