#ifndef DIY_SERVO_HPP
#define DIY_SERVO_HPP

// Modify pin definitions if necessary
#define SERVO1_PIN D1
#define SERVO2_PIN D2


#include <Arduino.h>
#include <Servo.h>

extern Servo servo1;
extern Servo servo2;
extern Servo servo3;

void servo_init();
void servo_reset(int servo);
void servo_update(int servo, int newAngle);

void servo_update_callback(int servo);
void servo_update_callback_rev(int servo);

#endif