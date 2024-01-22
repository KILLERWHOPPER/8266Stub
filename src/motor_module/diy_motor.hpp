#ifndef DIY_MOTOR_HPP
#define DIY_MOTOR_HPP

// Connect enable pins to 5v or 3v3
// Modify pin definitions if necessary
#define MOTOR1_PWM_A_PIN D6
#define MOTOR1_PWM_B_PIN D7

#define MOTOR2_PWM_A_PIN D5
#define MOTOR2_PWM_B_PIN D4

#include <Arduino.h>
#include <L298N.h>

extern L298N motor1;
extern L298N motor2;

void motor_init();
void set_motor_speed(int speed);
void move_forward();
void move_backward();
void turn_left();
void turn_right();
void stop();

#endif