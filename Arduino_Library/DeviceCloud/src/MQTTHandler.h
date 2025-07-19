#pragma once 
#include <PubSubClient.h>
#include <WiFiClientSecure.h>
class MQTTHandler{
    private:
    WiFiClientSecure espclient;
    PubSubClient client;
    const char* _broker;
    int _port;
    const char* _username;
    const char* _password;
    public:
    static const char* commandTopic;; 
    MQTTHandler();
    void MQTTConnect(const char* BROKER,int PORT,const char* MQTT_USERNAME,const char* MQTT_PASSWORD);
    void MQTTSubscribe(const char* topic);
    void SendData(const char* topic,const char* data);
    void SetActuatorTopic(const char* topic);
    void MQTTloop();
};