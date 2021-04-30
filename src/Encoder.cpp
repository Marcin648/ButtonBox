#include "Encoder.hpp"
#include <stdint.h>

#include "Arduino.h"

Encoder::Encoder(int pin_a, int pin_b){
    this->pin_a = pin_a;
    this->pin_b = pin_b;

    pinMode(pin_a, INPUT_PULLUP);
    pinMode(pin_b, INPUT_PULLUP);
}

void Encoder::update(){
    bool raw_a = !digitalRead(pin_a);
    bool raw_b = !digitalRead(pin_b);

    if(raw_a != last_a){
        if(raw_b != raw_a){
            state++;
        }else{
            state--;
        }
        if(state > 1 || state < -1){
            state = 0;
        }
    }
    
    last_a = raw_a;
    last_b = raw_b;
}