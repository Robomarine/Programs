#include <Servo.h>

#define MOT1PIN 1
#define MOT2PIN 2
#define MOT3PIN 3
#define MOT4PIN 4

#define CH3PIN 12
#define CH4PIN 13

Servo mot1;
Servo mot2;
Servo mot3;
Servo mot4;

void setup()
{
  Serial.begin(9600);
  mot1.attach(MOT1PIN);
  mot2.attach(MOT2PIN);
  mot3.attach(MOT3PIN);
  mot4.attach(MOT4PIN);
  pinMode(CH3PIN, INPUT);
  pinMode(CH4PIN, INPUT);
}

void loop()
{
  int pulseCh3 = pulseIn(CH3PIN, HIGH);
  int pulseCh4 = pulseIn(CH4PIN, HIGH);
  int valCh3 = map(pulseCh3, 1100, 1900, -100, 100);
  int valCh4 = map(pulseCh4, 1100, 1900, -100, 100);
  Serial.print(valCh3);
  Serial.print("    ");
  Serial.println(valCh4);
  if (abs(valCh3) > 50) {
    if (valCh3 > 0) { front(); } else { back(); }
  }
  else if (abs(valCh4) > 50)
  {
    if (valCh4 < 0) { left(); } else { right(); }
  }
  else
  {
    kill();
  }
  delay(20);
}

void front()
{
  mot1.write(180);
  mot2.write(180);
  mot3.write(0);
  mot4.write(0);
}

void back()
{
  mot1.write(0);
  mot2.write(0);
  mot3.write(180);
  mot4.write(180);
}

void left()
{
  mot1.write(180);
  mot2.write(0);
  mot3.write(0);
  mot4.write(180);
}

void right()
{
  mot1.write(0);
  mot2.write(180);
  mot3.write(180);
  mot4.write(0);
}

void kill()
{
  mot1.write(0);
  mot2.write(0);
  mot3.write(0);
  mot4.write(0);  
}