#include <DeviceCloud.h>
#define WIFI_SSID "your wifi ssid"
#define WIFI_PASSWORD "your wifi password"
#define MQTT_BROKER "hivemq broker id"
#define MQTT_PORT 8883
#define MQTT_USERNAME "Your mqtt username"
#define MQTT_PASSWORD "Your mqtt password"
#define SENSOR_TOPIC "Topic on which data will be sent"
#define ACTUATOR_TOPIC "Topic from which actuator commands will be received"
//Instantiate DeviceCloud object
DeviceCloudClass DeviceCloud;
void setup() {
  Serial.begin(115200);
  //Set the actuator pin,by default it is 4 
  //Connect to the wifi
  DeviceCloud.wifiConnect(WIFI_SSID, WIFI_PASSWORD);
  //Connect to the MQTT broker
  DeviceCloud.mqttConnect(MQTT_BROKER, MQTT_PORT, MQTT_USERNAME,MQTT_PASSWORD);
  //Subscribe to topics
  DeviceCloud.mqttSubscribe(SENSOR_TOPIC);
  DeviceCloud.mqttSubscribe(ACTUATOR_TOPIC);
  //Select the topic from which the commands will be comming from
  DeviceCloud.setActuatorTopic(ACTUATOR_TOPIC);
  //actuator.setPin()
}

void loop() {
  //Listen to incomming actuator commands and execute actions on GPIOS
  DeviceCloud.mqttloop();
  //Send data
  //DeviceCloud.sendData(topic,data)
}


