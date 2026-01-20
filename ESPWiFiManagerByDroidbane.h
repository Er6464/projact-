#ifndef ESPWiFiManagerByDroidbane_h
#define ESPWiFiManagerByDroidbane_h

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <LittleFS.h>
#include <ArduinoJson.h>

class ESPWiFiManagerByDroidbane {
public:
    ESPWiFiManagerByDroidbane(const char* apSSID = "ESP_Setup");
    
    void begin();                         // Setup işlemleri
    void loop();                          // loop içinde sürekli çağır
    bool saveCredentials(const char* ssid, const char* password);
    bool loadCredentials(String &ssid, String &password);
    bool clearCredentials();
    // Kullanıcının kendi callback’ini kaydetmesi için:
    void onMessage(void (*callback)(const String& message));
    // IP Getter
    String getIP();

private:
    ESP8266WebServer server;
    const char* apSSID;
    bool connected;

    // Callback için pointer
    void (*messageCallback)(const String& message) = nullptr;

    void handleWifi();
    void handleRestart();
    void handleWifiUpdate();
    void connectToWiFi(const String &ssid, const String &password);
};

#endif
