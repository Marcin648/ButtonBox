#include <Arduino.h>
#include <stdint.h>

#include "Joystick.h"
#include "ButtonBox.hpp"

//Encoder button
Button encoder_button(19);

//Encoder
Encoder encoder(18, 15);

//Buttons and switch
MatrixButton matrix_buttons[] = {
    MatrixButton(1, 14), MatrixButton(1, 16), MatrixButton(1, 10), MatrixButton(1, 9), MatrixButton(1, 8),
    MatrixButton(0, 14), MatrixButton(0, 16), MatrixButton(0, 10), MatrixButton(0, 9), MatrixButton(0, 8),
    MatrixButton(2, 14), MatrixButton(2, 16), MatrixButton(2, 10), MatrixButton(2, 9), MatrixButton(2, 8),
    MatrixButton(3, 14), MatrixButton(3, 16), MatrixButton(3, 10), MatrixButton(3, 9), MatrixButton(3, 8),
    MatrixButton(4, 14), MatrixButton(4, 16), MatrixButton(4, 10), MatrixButton(4, 9), MatrixButton(4, 8),
    MatrixButton(5, 14), MatrixButton(5, 16), MatrixButton(5, 10), MatrixButton(5, 9), MatrixButton(5, 8),
    MatrixButton(6, 14), MatrixButton(6, 16), MatrixButton(6, 10), MatrixButton(6, 9), MatrixButton(6, 8),
    MatrixButton(7, 14), MatrixButton(7, 16), MatrixButton(7, 10), MatrixButton(7, 9), MatrixButton(7, 8),
};

//Analog potentiometer
Analog analogs[] = {
    Analog(A3), Analog(A2),
};

Joystick_ Joystick(
    0x05,                   // Joystick ID
    JOYSTICK_TYPE_GAMEPAD,  // HID Type
    41, 2,                  // Button Count, Hat Switch Count
    false, false, true,     // X, Y, Z Axis
    false, false, true,     // Rx, Ry, Rz Axis
    false, false,           // rudder, throttle
    false, false, false     // accelerator, brake, steering
);  

void setup() {
    //Serial.begin(9600);

    Joystick.begin(false);
    Joystick.setZAxisRange(ANALOG_MIN, ANALOG_MAX);
    Joystick.setRzAxisRange(ANALOG_MIN, ANALOG_MAX);

    delay(1000);
}

void loop() {
    //Update state
    encoder.update();
    encoder_button.update();

    for(auto &button : matrix_buttons){
        button.update();
    }

    for(auto &analog : analogs){
        analog.update();
    }


    //Press gamepad

    for(size_t i = 0; i < 40; i++){
        Joystick.setButton(i, matrix_buttons[i].state);
    }

    Joystick.setButton(40, encoder_button.state);

    switch (encoder.state)
    {
    case -1:
        Joystick.setHatSwitch(0, 270);
        break;

    case 1:
        Joystick.setHatSwitch(0, 90);
        break;

    default:
        Joystick.setHatSwitch(0, -1);
    }

    Joystick.setZAxis(analogs[0].value);
    Joystick.setRzAxis(analogs[1].value);

    Joystick.sendState();
}