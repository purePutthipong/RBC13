#include "Arduino.h"
class Motor {

private:
  int pin1, pin2, enable;

public:
  Motor(int pin1, int pin2, int enable);
  void forward(int speed);
  void backwards(int speed);

  void stop();
};