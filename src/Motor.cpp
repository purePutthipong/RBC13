#include "Motor.h"

Motor::Motor(int pin1, int pin2, int enable) {
  this->pin1 = pin1;
  this->pin2 = pin2;
  this->enable = enable;

  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(enable, OUTPUT);
}

void Motor::forward(int speed) {
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, LOW);
  analogWrite(enable, map(speed, 0, 100, 0, 255));
}

void Motor::backwards(int speed) {
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, HIGH);
  analogWrite(enable, map(speed, 0, 100, 0, 255));
}

void Motor::stop() {
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
  analogWrite(enable, 0);
}