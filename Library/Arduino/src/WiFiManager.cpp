#include "WiFiManager.h"
#include <WiFi.h>
#include <WiFiClientSecure.h>
WiFiManager::WiFiManager() {
    // Constructor body
}

void WiFiManager::WIFIConnect(const char* WIFI_SSID,const char* WIFI_PASSWORD){
WiFi.begin(WIFI_SSID,WIFI_PASSWORD);
        while(WiFi.status()!=WL_CONNECTED){
            delay(500);
            Serial.println();
            Serial.print("Connecting to the WiFi...");
        }
        Serial.print("Connected to ");
}