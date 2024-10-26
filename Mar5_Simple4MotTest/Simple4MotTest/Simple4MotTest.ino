void setup()
{
  Serial.begin(9600);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT);
}

void loop()
{
  int pulseCh1 = pulseIn(10, HIGH);
  int pulseCh2 = pulseIn(11, HIGH);
  int pulseCh3 = pulseIn(12, HIGH);
  int pulseCh4 = pulseIn(13, HIGH);
  Serial.print(pulseCh1);
  Serial.print("    ");
  Serial.print(pulseCh2);
  Serial.print("    ");
  Serial.print(pulseCh3);
  Serial.print("    ");
  Serial.println(pulseCh4);
}