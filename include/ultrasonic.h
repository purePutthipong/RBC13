#include <Arduino.h>

class ultrasonic {
private:
  float duration = 0, distance = 0;
  byte trigger_, echo_;
  void init();
  

public:
  ultrasonic(byte trig, byte echo);
  int getDuration();
  // int lowpassDuration(int distance);
};