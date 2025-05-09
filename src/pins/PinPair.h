//
// Created by backo on 04/03/25.
//

#ifndef CALCULADORA_ARDUINO_PINPAIR_H
#define CALCULADORA_ARDUINO_PINPAIR_H

#include <Arduino.h>

struct PinPair {
     union  {
        byte start;
        byte in;

    };
    union {
        byte end;
        byte out;
    };

    constexpr int count() const {
        return this->end - this->start + 1;
    }

    int getPin(int index) {
        return index < this->count() ? start + index : -1;
    }
};


#endif //CALCULADORA_ARDUINO_PINPAIR_H
