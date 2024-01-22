#ifndef DIY_WIFI_HPP
#define DIY_WIFI_HPP

#define WIFI_SSID "Galaxy"
#define WIFI_PASSWORD "1029946339"

#include <Arduino.h>
#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <Ticker.h>

extern ESP8266WiFiMulti wifiMulti;
extern ESP8266WebServer server;

void wifi_init();

void handleTest();

void handleForward();

void handleBackward();

void handleLeft();

void handleRight();

void handleStop();

void handleAction1();

void handleAction1Stop();

void handleAction2();

void handleAction2Stop();

void handleSpeedUp();

void handleSpeedDown();

void handleRiseUp();

void handleRiseUpStop();

void handleFallDown();

void handleFallDownStop();

#endif