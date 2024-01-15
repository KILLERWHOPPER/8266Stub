#include "diy_motor.hpp"

void motor_init() {
  L298N motor1(MOTOR1_PWM_A_PIN, MOTOR1_PWM_B_PIN);
  L298N motor2(MOTOR2_PWM_A_PIN, MOTOR2_PWM_B_PIN);
}

void set_motor_speed(int speed) {
  motor1.setSpeed(speed);
  motor2.setSpeed(speed);
}

void stop() {
  motor1.stop();
  motor2.stop();
}

void move_forward() {
  set_motor_speed(255);
  motor1.forward();
  motor2.forward();
}

void move_backward() {
  set_motor_speed(255);
  motor1.backward();
  motor2.backward();
}

void turn_left() {
  set_motor_speed(127);
  motor1.backward();
  motor2.forward();
}

void turn_right() {
  set_motor_speed(127);
  motor1.forward();
  motor2.backward();
}