#include "diy_motor.hpp"

L298N motor1(MOTOR1_PWM_A_PIN, MOTOR1_PWM_B_PIN);
L298N motor2(MOTOR2_PWM_A_PIN, MOTOR2_PWM_B_PIN);

int pwm_speed = 0;

void motor_init(){
    pinMode(MOTOR1_PWM_A_PIN, OUTPUT);
    pinMode(MOTOR1_PWM_B_PIN, OUTPUT);
    pinMode(MOTOR2_PWM_A_PIN, OUTPUT);
    pinMode(MOTOR2_PWM_B_PIN, OUTPUT);
}

void set_motor_speed(int speed) {
    motor1.setSpeed(speed);
    motor2.setSpeed(speed);
  pwm_speed = speed;
  if (pwm_speed > 255) {
    pwm_speed = 255;
  }
  if (pwm_speed < 0) {
    pwm_speed = 0;
  }
  Serial.printf("SetSpeed: %d\n", speed);
}

void stop() {
  motor1.stop();
  motor2.stop();
}

void move_forward() {
  motor1.forward();
  motor2.forward();
}

void move_backward() {
  motor1.backward();
  motor2.backward();
}

void turn_left() {
  motor1.forward();
  motor2.backward();
}

void turn_right() {
  motor1.backward();
  motor2.forward();
}