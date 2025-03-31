#include "ultrasonic.h"

ultrasonic::ultrasonic(byte trig, byte echo)
  : trigger_(trig), echo_(echo) {
  init();
}

void ultrasonic::init() {
  pinMode(trigger_, OUTPUT);
  pinMode(echo_, INPUT);
}

int ultrasonic::getDuration() {

  digitalWrite(trigger_, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger_, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger_, LOW);
  duration = pulseIn(echo_, HIGH);
  distance = duration * 340 / 20000;
  distance = constrain(distance, 0, 100);
  return distance;
}

