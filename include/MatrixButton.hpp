#pragma once

class MatrixButton{
private:
    int pin_row;
    int pin_column;

    bool raw_state;
    unsigned long toggle_time;
public:
    bool state;

    MatrixButton(int pin_column, int pin_row);

    void update();
};