//
// Created by backo on 17/04/25.
//

#ifndef CALCULADORA_ARDUINO_PINSET_H
#define CALCULADORA_ARDUINO_PINSET_H

#include "../utilities/VariadicAggregation.h"
#include "PinPair.h"
/*
class PinSet : VariadicAggregation<PinPair> {
public:
    using VariadicAggregation<PinPair>::VariadicAggregation;
    using VariadicAggregation<PinPair>::size;

    const PinPair* pairs = VariadicAggregation<PinPair>::array;

    int count() const {
        int r = 0;
        for (int i = 0; i < size; ++i) {
            r += this->pairs[i].count();
        }

        return r;
    };


    int getPin(int index) {
        ++index; // index comença per 0, però és millor començar per 1 quan es fa servir count()

        int i = 0;
        while (i < size && index > pairs[i].count()) {
            ++i;
        }
    }


    template<class T, int Length>
    T* constructRange(int indStart, int indEnd) {

    }
};
*/

#endif //CALCULADORA_ARDUINO_PINSET_H
