#include <Arduino.h>
#include "wifi_module/diy_wifi.hpp"
#include "servo_module/diy_servo.hpp"
#include "motor_module/diy_motor.hpp"

void setup() {
    Serial.begin(9600);
    wifi_init();
    servo_init();
    motor_init();
}

void loop() {
    server.handleClient();
    delay(20);
}
