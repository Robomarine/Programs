#include "R6B_READ.h"

R6B_Channel ch3;
R6B_Channel ch4;

void calcPulseCh3() { calcPulse(ch3); }
void calcPulseCh4() { calcPulse(ch4); }

void setup() {
  ch3.attach(2);
  ch4.attach(3);

  attachInterrupt(digitalPinToInterrupt(2), calcPulseCh3, CHANGE);
  attachInterrupt(digitalPinToInterrupt(3), calcPulseCh4, CHANGE);
  
  Serial.begin(9600);
}

void loop() {
  Serial.print("CH3: ");
  Serial.print(ch3.lastDeg);
  Serial.print("    CH4: ");
  Serial.println(ch4.lastDeg);
}
