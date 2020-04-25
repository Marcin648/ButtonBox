#pragma once

class Encoder{
private:
    int pinA;
    int pinB;

    bool last_a;
    bool last_b;
public:
    int state;

    Encoder(int pinA, int pinB);

    void update();
    void print();
};