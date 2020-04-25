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

    if(rawA != last_a){
        if(rawB != rawA){
            state++;
        }else{
            state--;
        }
        if(state > 1 || state < -1){
            state = 0;
        }
    }
    
    last_a = rawA;
    last_b = rawB;
}

void Encoder::print(){
    Serial.print(state);
    Serial.print(' ');
}
