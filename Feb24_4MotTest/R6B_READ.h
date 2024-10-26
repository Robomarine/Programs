class R6B_Channel
{
public:
  volatile int digitalPin = 2;
  volatile int minPulseWidth = 1000;
  volatile int maxPulseWidth = 2000;
  R6B_Channel();                                                          // Constructor
  ~R6B_Channel();                                                         // Destructor (Ooh fancy!)
  void attach(int digitalPin);
  void attach(int digitalPin, int minPulseWidth, int maxPulseWidth);
  volatile unsigned long ulPulseStart = 0;
  volatile int lastDeg = 90;
};

R6B_Channel::R6B_Channel() {}

R6B_Channel::~R6B_Channel()
{
  detachInterrupt(digitalPinToInterrupt(this->digitalPin));
}

void R6B_Channel::attach(int digitalPin)
{
  this->digitalPin = digitalPin;
}

void R6B_Channel::attach(int digitalPin, int minPulseWidth, int maxPulseWidth)
{
  this->digitalPin = digitalPin;
  this->minPulseWidth = minPulseWidth;
  this->maxPulseWidth = maxPulseWidth;
}

void calcPulse(R6B_Channel r6b_channel)
{
  if (digitalRead(r6b_channel.digitalPin) == HIGH)
  {
    r6b_channel.ulPulseStart = micros();
  }
  else
  {
    unsigned long period = micros() - r6b_channel.ulPulseStart;
    r6b_channel.ulPulseStart = 0;
    r6b_channel.lastDeg = (int) map(period, r6b_channel.minPulseWidth, r6b_channel.maxPulseWidth, 0, 180);
  }
}