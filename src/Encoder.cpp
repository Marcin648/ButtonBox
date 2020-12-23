#include "Encoder.hpp"
#include <stdint.h>

#include "Arduino.h"

Encoder::Encoder(int pinA, int pinB){
    this->pinA = pinA;
    this->pinB = pinB;

    pinMode(pinA, INPUT_PULLUP);
    pinMode(pinB, INPUT_PULLUP);
}

void Encoder::update(){
    bool rawA = !digitalRead(pinA);
    bool rawB = !digitalRead(pinB);

    if(rawB != last_b){
        state--;
        if(state < -1){
            state = 0;
        }
    }
    last_b = rawB;

    if(rawA != last_a){
        state++;
        if(state > 1){
            state = 0;
        }
    }
    last_a = rawA;
}

void Encoder::print(){
    Serial.print(state);
    Serial.print(' ');
}
