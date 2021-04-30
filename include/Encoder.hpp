#pragma once

class Encoder{
private:
    int pin_a;
    int pin_b;

    bool last_a;
    bool last_b;
public:
    int state;

    Encoder(int pin_a, int pin_b);

    void update();
};