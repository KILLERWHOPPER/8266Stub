#include "diy_servo.hpp"

Servo servo1;
Servo servo2;
Servo servo3;

int local_angle_1 = 0;
int local_angle_2 = 0;

void servo_init() {
  servo1.attach(SERVO1_PIN);
  servo2.attach(SERVO2_PIN);

  servo1.write(0);
  servo2.write(0);

  Serial.println("\nServo Initialized");
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
    servo1.write(0);
    local_angle_1 = 0;
  } else if (servo == 2) {
    servo2.write(0);
    local_angle_2 = 0;
  }
  Serial.printf("Servo %d Reset\n", servo);
}

void servo_update_callback(int servo) {
  if (servo == 1) {
    servo1.write(local_angle_1);
    local_angle_1 += 10;
    if (local_angle_1 >= 180) {
      local_angle_1 = 180;
    }
    Serial.printf("Servo %d Updated: %d\n", servo, local_angle_1);
  } else if (servo == 2) {
    servo2.write(local_angle_2);
    local_angle_2 += 10;
    if (local_angle_2 >= 180) {
      local_angle_2 = 180;
    }
    Serial.printf("Servo %d Updated: %d\n", servo, local_angle_2);
  }
}

void servo_update_callback_rev(int servo) {
  if (servo == 1) {
    servo1.write(local_angle_1);
    local_angle_1 -= 10;
    if (local_angle_1 <= 0) {
      local_angle_1 = 0;
    }
    Serial.printf("Servo %d Updated: %d\n", servo, local_angle_1);
  } else if (servo == 2) {
    servo2.write(local_angle_2);
    local_angle_2 -= 10;
    if (local_angle_2 <= 0) {
      local_angle_2 = 0;
    }
    Serial.printf("Servo %d Updated: %d\n", servo, local_angle_2);
  }
}