#include <Arduino.h>
#include "wifi_module/diy_wifi.hpp"
#include "servo_module/diy_servo.hpp"

void setup() {
    Serial.begin(115200);
    wifi_init();
    servo_init();
}

void loop() {
    delay(1000);
}
