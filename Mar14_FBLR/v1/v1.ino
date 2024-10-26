#include <Servo.h>

#define MOT1PIN 7
#define MOT2PIN 8
#define MOT3PIN 9
#define MOT4PIN 10

#define CH3PIN 12
#define CH4PIN 13

Servo mot1;
Servo mot2;
Servo mot3;
Servo mot4;

int mot1deg = 0;
int mot2deg = 0;
int mot3deg = 0;
int mot4deg = 0;

int mot1degT = 0;
int mot2degT = 0;
int mot3degT = 0;
int mot4degT = 0;

int pulseCh3 = 0;
int pulseCh4 = 0;

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
  pulseCh3 = pulseIn(CH3PIN, HIGH);
  pulseCh4 = pulseIn(CH4PIN, HIGH);
  mot1deg = map(pulseCh3, 1100, 1900, 0, 180);
  mot2deg = map(pulseCh4, 1100, 1900, 0, 180);
  mot1.write(mot1deg);
  mot2.write(mot2deg);
  Serial.print(mot1deg); Serial.print("    ");
  Serial.println(mot2deg);
}