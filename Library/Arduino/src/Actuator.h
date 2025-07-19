//Get commands transiting from the broker and translate them into GPIO commands
#pragma once
#include <Arduino.h>

class Actuator {
private:
    byte pin;

public:
    Actuator(int pin);
    void init();
    void update(String state);
};



