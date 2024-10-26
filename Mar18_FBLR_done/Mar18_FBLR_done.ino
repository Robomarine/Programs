#include <Servo.h>

#define MOT1PIN 4
#define MOT2PIN 5
#define MOT3PIN 6
#define MOT4PIN 7

#define CH3PIN 12
#define CH4PIN 13

Servo mot1;
Servo mot2;
Servo mot3;
Servo mot4;

Servo mots[] = { mot1, mot2, mot3, mot4 };
int motpins[] = { MOT1PIN, MOT2PIN, MOT3PIN, MOT4PIN };

int pulseCh3 = 0;
int degCh3 = 0;
int pulseCh4 = 0;
int degCh4 = 0;

void setup() {
  Serial.begin(9600);
  pinMode(CH3PIN, INPUT);
  pinMode(CH4PIN, INPUT);
  Serial.println("Programming start");
  programESC(4);
  Serial.println("Programming end");
}

void programESC(int count) {
  for (int i = 0; i < count; i++) {
    pinMode(motpins[i], INPUT);
  }
  delay(15000);
  for (int i = 0; i < count; i++) {
    /* code */
    mots[i].attach(motpins[i], 1000, 2000);
    mots[i].write(180);
  }
  delay(5000);
  for (int i = 0; i < count; i++) {
    mots[i].write(0);
  }
  delay(5000);
}

void loop() {
  pulseCh3 = pulseIn(CH3PIN, HIGH);
  pulseCh4 = pulseIn(CH4PIN, HIGH);
  degCh3 = map(pulseCh3, 1200, 1800, -180, 180);
  degCh4 = map(pulseCh4, 1200, 1800, -180, 180);
  if (pulseCh3 == 0 || pulseCh4 == 0) { return; }
  if (degCh3 > 90) {
    mot1.write(135);
    mot2.write(135);
    mot3.write(0);
    mot4.write(0);
  } else if (degCh3 < -90) {
    mot1.write(0);
    mot2.write(0);
    mot3.write(135);
    mot4.write(135);
  } else if (degCh4 > 90) {
    mot1.write(0);
    mot2.write(135);
    mot3.write(135);
    mot4.write(0);
  } else if (degCh4 < -90) {
    mot1.write(135);
    mot2.write(0);
    mot3.write(0);
    mot4.write(135);
  } else {
    mot1.write(0);
    mot2.write(0);
    mot3.write(0);
    mot4.write(0);
  }
}