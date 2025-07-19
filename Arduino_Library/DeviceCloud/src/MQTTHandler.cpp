#include "MQTTHandler.h"
#include "DeviceCloud.h"
#include "certificate.h"
#include "Actuator.h"
Actuator actuator(2);//Initialize the actuator pin to 4
MQTTHandler::MQTTHandler():client(espclient){}
const char* MQTTHandler::commandTopic = nullptr;
void callback(char *topic, byte *payload, unsigned int length) {
     String state; 
    if (strcmp(topic,MQTTHandler::commandTopic) == 0){
        for(int i=0;i<length;i++){
        state+=(char) payload[i];
        }
       actuator.update(state);
      }
    //Add new topics for actuators
     else{
      Serial.println("Unrecognized device");
     } 
    };
//mqttConnect
void MQTTHandler::MQTTConnect(const char* BROKER, int PORT, const char* MQTT_USERNAME, const char* MQTT_PASSWORD) {
    _broker = BROKER;
    _port = PORT;
    _username = MQTT_USERNAME;
    _password = MQTT_PASSWORD;

    espclient.setCACert(root_ca);
    client.setServer(_broker, _port);
    client.setCallback(callback);

    String client_id = "device1";
    int attempts = 0;

    Serial.print("Connecting to MQTT broker...");

    while (!client.connected() && attempts < 5) {
        Serial.print(".");
        if (client.connect(client_id.c_str(), _username, _password)) {
            Serial.println("\nMQTT broker connected");
            return;
        } else {
            Serial.print("\nFailed, state: ");
            Serial.println(client.state());
            delay(2000);  // Important to prevent WDT
            attempts++;
        }
    }

    if (!client.connected()) {
        Serial.println("MQTT connection failed after 5 attempts. Skipping...");
    }
}

//incoming messages
//For each new incoming message,execute an action based on the topic

void MQTTHandler::SetActuatorTopic(const char* topic) {
    commandTopic = topic;
}
//mqttSubscribe
void MQTTHandler::MQTTSubscribe(const char* topic){
 client.subscribe(topic);
}
//send data
void MQTTHandler::SendData(const char* topic,const char* data){
  client.publish(topic,data);
}
//mqttloop
void MQTTHandler::MQTTloop(){
 if (!client.connected()) {
            MQTTConnect(_broker,_port,_username,_password);  // auto-reconnect
        }
        client.loop();
}