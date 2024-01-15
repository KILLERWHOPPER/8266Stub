#include "diy_servo.hpp"

Servo servo1;
Servo servo2;

void servo_init() {
    // TODO: Put servo initialization code here
    servo1.attach(SERVO1_PIN);
    servo2.attach(SERVO2_PIN);

    servo1.write(90);
    servo2.write(90);

    Serial.println("Servo Initialized");
}

void servo_update(Servo *servo, int newAngle) {
    // TODO: Put servo update code here
    servo->write(newAngle);

    Serial.println("Servo Updated: " + String(newAngle));
}

void servo_reset(Servo *servo) {
    servo->write(90);

    Serial.println("Servo Reset");
}