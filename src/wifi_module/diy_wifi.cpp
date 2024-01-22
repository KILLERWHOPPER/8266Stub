#include "diy_wifi.hpp"

#include "motor_module/diy_motor.hpp"
#include "servo_module/diy_servo.hpp"

ESP8266WiFiMulti wifiMulti;
ESP8266WebServer server(80);
Ticker timer;

int servo_angle = 0;
int motor_speed = 100;

void wifi_init() {
  wifiMulti.addAP(WIFI_SSID, WIFI_PASSWORD);
  Serial.printf("Connecting to %s ...", WIFI_SSID);
  while (wifiMulti.run() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected!");
  Serial.printf("IP address: %s", WiFi.localIP().toString().c_str());

  server.on("/test", HTTP_GET, handleTest);
  server.on("/forward", HTTP_GET, handleForward);
  server.on("/backward", HTTP_GET, handleBackward);
  server.on("/left", HTTP_GET, handleLeft);
  server.on("/right", HTTP_GET, handleRight);
  server.on("/stop", HTTP_GET, handleStop);
  server.on("/action1", HTTP_GET, handleAction1);
  server.on("/action1_stop", HTTP_GET, handleAction1Stop);
  server.on("/action2", HTTP_GET, handleAction2);
  server.on("/action2_stop", HTTP_GET, handleAction2Stop);
  server.on("/speedup", HTTP_GET, handleSpeedUp);
  server.on("/speeddown", HTTP_GET, handleSpeedDown);
  server.on("/riseup", HTTP_GET, handleRiseUp);
  server.on("/riseup_stop", HTTP_GET, handleRiseUpStop);
  server.on("/falldown", HTTP_GET, handleFallDown);
  server.on("/falldown_stop", HTTP_GET, handleFallDownStop);

  //   server.on("/action2_stop", HTTP_GET, handleAction2Stop);
  //   server.on("/action3_stop", HTTP_GET, handleAction3Stop);

  server.begin();
}

void handleForward() {
  server.send(200, "text/html", "Forward");
  // TODO: Put control code here
  move_forward();
  Serial.println("Forward");
}

void handleBackward() {
  server.send(200, "text/html", "Backward");
  // TODO: Put control code here
  move_backward();
  Serial.println("Backward");
}

void handleLeft() {
  server.send(200, "text/html", "Left");
  // TODO: Put control code here
  turn_left();
  Serial.println("Left");
}

void handleRight() {
  server.send(200, "text/html", "Right");
  // TODO: Put control code here
  turn_right();
  Serial.println("Right");
}

void handleStop() {
  server.send(200, "text/html", "Stop");
  // TODO: Put control code here
  stop();
  Serial.println("Stop");
}

// Hold to rotate clockwise
void handleAction1() {
  server.send(200, "text/html", "RotateClock");
  timer.attach_ms(40, servo_update_callback_rev, 2);
  Serial.println("Action1");
}

void handleAction1Stop() {
  server.send(200, "text/html", "Action1Stop");
  // TODO: Put control code here
  timer.detach();
  Serial.println("Action1Stop");
}

// Hold to rotate counter-clockwise
void handleAction2() {
  server.send(200, "text/html", "Action2");
  timer.attach_ms(40, servo_update_callback, 2);
  Serial.println("Action2");
}

void handleAction2Stop() {
  server.send(200, "text/html", "Action2Stop");
  // TODO: Put control code here
  timer.detach();
  Serial.println("Action2Stop");
}

void handleTest() {
  server.send(200, "text/html", "Test");
  // TODO: Put control code here
  Serial.println("Test");
}

void handleSpeedUp() {
  server.send(200, "text/html", "SpeedUp: %d", motor_speed);
  // TODO: Put control code here
  motor_speed = motor_speed + 10;
  if (motor_speed > 255) {
    motor_speed = 255;
  }

  set_motor_speed(motor_speed);
  Serial.println("SetSpeed");
}

void handleSpeedDown() {
  server.send(200, "text/html", "SpeedDown: %d", motor_speed);
  // TODO: Put control code here
  motor_speed = motor_speed - 10;
  if (motor_speed < 0) {
    motor_speed = 0;
  }
  set_motor_speed(motor_speed);
  Serial.println("SetSpeed");
}

void handleRiseUp() {
  server.send(200, "text/html", "RiseUp: %d", servo_angle);
  // TODO: Put control code here
  timer.attach_ms(40, servo_update_callback_rev, 1);
  Serial.println("RiseUp");
}

void handleRiseUpStop() {
  server.send(200, "text/html", "RiseUpStop");
  // TODO: Put control code here
  timer.detach();
  Serial.println("RiseUpStop");
}

void handleFallDown() {
  server.send(200, "text/html", "FallDown: %d", servo_angle);
  // TODO: Put control code here
  timer.attach_ms(100, servo_update_callback, 1);
  Serial.println("FallDown");
}

void handleFallDownStop() {
  server.send(200, "text/html", "FallDownStop");
  // TODO: Put control code here
  timer.detach();
  Serial.println("FallDownStop");
}