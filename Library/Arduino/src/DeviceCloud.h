#ifndef DEVICE_CLOUD_H
#define DEVICE_CLOUD_H
#include "WIFIManager.h"
#include "MQTTHandler.h"
class DeviceCloudClass{
    private:
    MQTTHandler mqtt;
    WiFiManager wifi;
    public:
    //const char* commandTopic;
    DeviceCloudClass();
    void wifiConnect(const char* WIFI_SSID,const char* WIFI_PASSWORD);
    void mqttConnect(const char* BROKER,int PORT,const char* MQTT_USERNAME,const char* MQTT_PASSWORD);
    void mqttSubscribe(const char* topic);
    void setActuatorTopic(const char* topic);
    void sendData(const char* topic,const char* data);
    void mqttloop();
    };
    extern DeviceCloudClass DeviceCloud;
    
    #endif