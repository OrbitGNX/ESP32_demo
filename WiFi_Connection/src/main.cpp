/*===========================================================================
                              WIFI CONNECTION
=============================================================================
Description:
  This Arduino sketch demonstrates a simple WiFi connection status indicator
  using an ESP32. The program connects the device to a specified WiFi network
  and provides visual and serial feedback about the connection status.

Design Engineer:
  Gyro Madrona

Date:
  29 Mar 2026
-----------------------------------------------------------------------------*/
#include <Arduino.h>
#include <WiFi.h>

// WiFi info
#define WIFI_SSID "Orbit"
#define WIFI_PASSWORD "PLDTWIFI12345"

// Variables
bool  is_connected  = false;

void setup() {
  Serial.begin(921600);
  pinMode(LED_BUILTIN, OUTPUT);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.println("starting");
}

void loop() {
  if(WiFi.status() == WL_CONNECTED && !is_connected){
    Serial.println("Connected");
    digitalWrite(LED_BUILTIN, HIGH);
    is_connected = true;
  }

  if(WiFi.status() != WL_CONNECTED){
    Serial.println(".");
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    delay(1000);
    is_connected = false;
  }
}