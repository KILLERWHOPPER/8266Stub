#include "diy_servo.hpp"

Servo servo1;
Servo servo2;

void servo_init() {
    servo1.attach(SERVO1_PIN);
    servo2.attach(SERVO2_PIN);

    servo1.write(90);
    servo2.write(90);

    Serial.println("Servo Initialized");
}

void servo_update(int servo, int newAngle) {
    if (servo == 1) {
        servo1.write(newAngle);
    } else if (servo == 2) {
        servo2.write(newAngle);
    }
    Serial.printf("Servo %d Updated: %d\n", servo, newAngle);
}

void servo_reset(int servo) {
  if (servo == 1) {
    servo1.write(90);
  } else if (servo == 2) {
    servo2.write(90);
  }

  Serial.printf("Servo %d Reset\n", servo);
}