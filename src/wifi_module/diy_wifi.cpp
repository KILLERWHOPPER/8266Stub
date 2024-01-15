#include "diy_wifi.hpp"

ESP8266WiFiMulti wifiMulti;
ESP8266WebServer server(80);

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
  server.begin();
}

void handleForward() {
  server.send(200, "text/html", "Forward");
  // TODO: Put control code here
  Serial.println("Forward");
}

void handleBackward() {
  server.send(200, "text/html", "Backward");
  // TODO: Put control code here
  Serial.println("Backward");
}

void handleLeft() {
  server.send(200, "text/html", "Left");
  // TODO: Put control code here
  Serial.println("Left");
}

void handleRight() {
  server.send(200, "text/html", "Right");
  // TODO: Put control code here
  Serial.println("Right");
}

void handleStop() {
  server.send(200, "text/html", "Stop");
  // TODO: Put control code here
  Serial.println("Stop");
}

void handleTest() {
  server.send(200, "text/html", "Test");
  // TODO: Put control code here
  Serial.println("Test");
}