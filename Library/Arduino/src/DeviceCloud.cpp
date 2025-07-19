#include "DeviceCloud.h"
#include "Actuator.h"
#include "certificate.h"
#include "MQTTHandler.h"
#include "WiFiManager.h"
DeviceCloudClass::DeviceCloudClass(): mqtt(), wifi() {} 
void DeviceCloudClass::wifiConnect(const char* WIFI_SSID,const char* WIFI_PASSWORD){
wifi.WIFIConnect(WIFI_SSID,WIFI_PASSWORD);
}
void DeviceCloudClass::mqttConnect(const char* BROKER,int PORT,const char* MQTT_USERNAME,const char* MQTT_PASSWORD){
  mqtt.MQTTConnect(BROKER,PORT,MQTT_USERNAME,MQTT_PASSWORD);
}
void DeviceCloudClass::mqttSubscribe(const char* topic){
  mqtt.MQTTSubscribe(topic);
}
void DeviceCloudClass::setActuatorTopic(const char* topic){
  mqtt.SetActuatorTopic(topic);
}
void DeviceCloudClass::sendData(const char* topic,const char* data){
  mqtt.SendData(topic,data);
}
void DeviceCloudClass::mqttloop(){
  mqtt.MQTTloop();
}
