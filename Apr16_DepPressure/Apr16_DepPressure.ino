#include <MS5837.h>
#include <Wire.h>

#define WEIGHT 5

#define ATM 989 // Atmospheric pressure in mBar
#define RHO 990 // Water density in kg/m^3
#define g 9.8 // Constant 'g' in m/s^2

MS5837 depSensor;

void setup()
{
  Serial.begin(9600);
  Wire.begin();
  while (!depSensor.init())
  {
    Serial.println("Connection failed");
    delay(500);
  }
  Serial.println("Connection successful");
  
  depSensor.setModel(MS5837::MS5837_30BA);
  depSensor.setFluidDensity(RHO);
}

float h_ = 0;

void loop()
{
  depSensor.read();
  float p = depSensor.pressure();
  if (p<0) { return; }
  p -= ATM;
  p *= 100;
  float h = 100*p/(RHO*g);
  float d = depSensor.depth();
  h_ = ((WEIGHT-1)*h_ + h)/WEIGHT;
  Serial.print(h);
  Serial.print("    ");
  Serial.print(d);
  Serial.print("    ");
  Serial.println(h_);
  delay(500);
}