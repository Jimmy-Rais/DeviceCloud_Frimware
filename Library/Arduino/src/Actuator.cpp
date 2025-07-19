#include "Actuator.h"
#include <Arduino.h>
Actuator::Actuator(int pin){
  this ->pin=pin;
  init();
}
void Actuator::init(){
   pinMode(pin, OUTPUT);
   update("off");
}
void Actuator ::update(String state){
    if (state == "on") {
            digitalWrite(pin, HIGH);
        } else if (state == "off") {
            digitalWrite(pin, LOW);
        } else {
            Serial.println("Unrecognized state: " + state);
        }
}