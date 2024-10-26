#include "R6B_READ.h"
#include "Vector2D.h"
#include <Servo.h>

const int CH3PIN = 2;
const int CH4PIN = 3;
const int MOTAPIN = 7;
const int MOTBPIN = 8;
const int MOTCPIN = 9;
const int MOTDPIN = 10;

const float R2 = 0.707F; // Square root of 2

const Vector2D MOTAVECT = Vector2D(R2,R2);
const Vector2D MOTBVECT = Vector2D(-R2,R2);
const Vector2D MOTCVECT = Vector2D(R2,-R2);
const Vector2D MOTDVECT = Vector2D(-R2,-R2);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

R6B_Channel ch3;
R6B_Channel ch4;

void calcPulseCh3() { calcPulse(ch3); }
void calcPulseCh4() { calcPulse(ch4); }

Vector2D inp_ch3_ch4 = Vector2D(0,0);

Servo motA;
Servo motB;
Servo motC;
Servo motD;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void setup()
{
  ch3.attach(CH3PIN);
  ch4.attach(CH4PIN);

  motA.attach(MOTAPIN);
  motB.attach(MOTBPIN);
  motC.attach(MOTCPIN);
  motD.attach(MOTDPIN);

  attachInterrupt(digitalPinToInterrupt(CH3PIN), calcPulseCh3, CHANGE);
  attachInterrupt(digitalPinToInterrupt(CH4PIN), calcPulseCh4, CHANGE);
}

void loop()
{
  inp_ch3_ch4.x = (ch3.lastDeg-90)/180;
  inp_ch3_ch4.y = (ch4.lastDeg-90)/180;
  inp_ch3_ch4.clampUnit();
  motA.write(180*dotProduct(MOTAVECT, inp_ch3_ch4)); // Use with bidirectional ESC only
  motB.write(180*dotProduct(MOTBVECT, inp_ch3_ch4)); // Use with bidirectional ESC only
  motC.write(180*dotProduct(MOTCVECT, inp_ch3_ch4)); // Use with bidirectional ESC only
  motD.write(180*dotProduct(MOTDVECT, inp_ch3_ch4)); // Use with bidirectional ESC only
}