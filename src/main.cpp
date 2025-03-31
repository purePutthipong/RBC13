#include <Arduino.h>

#include "ultrasonic.h"
#include "Motor.h"

#define trigger 6
#define echo 7

#define ENA 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define ENB 5

int var1 = 200;

ultrasonic ultra1(trigger, echo);
Motor motor1(PIN1, PIN2, ENA);
Motor motor2(PIN3, PIN4, ENB);

float x[] = {0, 0, 0};
float y[] = {0, 0, 0};
int k = 0;

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  int duration = ultra1.getDuration();

  float t = micros() / 1.0e6;
  x[0] = duration;

  float b[] = {0.00024132, 0.00048264, 0.00024132};
  float a[] = {1.95558189, -0.95654717};
  y[0] = a[0] * y[1] + a[1] * y[2] + b[0] * x[0] + b[1] * x[1] + b[2] * x[2];

  if (k % 3 == 0)
  {
    Serial.print(2 * x[0]);
    Serial.print(" \t");
    Serial.print(2 * y[0]);
    Serial.print(" \t");
    Serial.print(180);
    Serial.print(" \t");
    Serial.println(0);
  }

  delay(1); // Wait 1ms
  for (int i = 1; i >= 0; i--)
  {
    x[i + 1] = x[i]; // store xi
    y[i + 1] = y[i]; // store yi
  }

  k = k + 1;
  int speed = map(2 * y[0], 0, 60, 0, 80);
  motor1.forward(speed);
  motor2.forward(speed);
}
