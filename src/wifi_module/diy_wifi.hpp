#ifndef DIY_WIFI_HPP
#define DIY_WIFI_HPP

#define WIFI_SSID "KILLEERWHOPPER_2.4"
#define WIFI_PASSWORD "84639188"

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WebServer.h>

extern ESP8266WiFiMulti wifiMulti;
extern ESP8266WebServer server;

void wifi_init();

void handleTest();

void handleForward();

void handleBackward();

void handleLeft();

void handleRight();

void handleStop();

#endif