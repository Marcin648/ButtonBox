#include "MatrixButton.hpp"
#include "ButtonBox.hpp"

#include "Arduino.h"

MatrixButton::MatrixButton(int pin_column, int pin_row){
    this->pin_column = pin_column;
    this->pin_row = pin_row;

    pinMode(pin_column, INPUT);
    pinMode(pin_row, INPUT);
}

void MatrixButton::update(){
    pinMode(pin_column, OUTPUT);
    pinMode(pin_row, INPUT_PULLUP);
    digitalWrite(pin_column, LOW);

    raw_state = !digitalRead(pin_row);

    if(state != raw_state){
        unsigned long toggle_dtime = millis() - toggle_time;
        if(
            raw_state ||
            (toggle_dtime > DEBOUNCE_TIME)
        ){
            state = raw_state;
        }
        toggle_time = millis();
    }

    pinMode(pin_column, INPUT);
    pinMode(pin_row, INPUT);
}
