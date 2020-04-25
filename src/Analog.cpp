#include "Analog.hpp"

#include "Arduino.h"

Analog::Analog(int pin){
    this->pin = pin;
    pinMode(pin, INPUT);
}

void Analog::update(){
    int raw_value = analogRead(pin);
    value = raw_value; //(int16_t)map(raw_value, 0, 1023, INT16_MIN, INT16_MAX);
}

void Analog::print(){
    Serial.print(value);
    Serial.print(' ');
}