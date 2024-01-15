#ifndef DIY_SERVO_HPP
#define DIY_SERVO_HPP

// Modify pin definitions if necessary
#define SERVO1_PIN D1
#define SERVO2_PIN D2

#include <Arduino.h>
#include <Servo.h>

extern Servo servo1;
extern Servo servo2;

void servo_init();
void servo_reset(Servo *servo);
void servo_update(Servo *servo, int newAngle);

#endif