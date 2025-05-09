//
// Created by backo on 12/04/25.
//

#ifndef CALCULADORA_ARDUINO_SIGNALLIGHTS_H
#define CALCULADORA_ARDUINO_SIGNALLIGHTS_H

#include "SignalLight.h"
#include "Calculator.h"
#include "Keypad.h"


class SignalLights {
public:
    static constexpr int signalLightsNumber = 5;
private:
    static SignalLight leds[signalLightsNumber];
public:

    static void updateAll(const Calculator* calculator, const Display* display, const Keypad* keypad);

    static void begin() {
        for (auto& signalLight : SignalLights::leds) signalLight.begin();
    };
/*
    static void test() {
        auto ptr = leds;

        for (int i = 0; i < signalLightsNumber; ++i) {
            ptr->
        }
    }
    */
};


#endif //CALCULADORA_ARDUINO_SIGNALLIGHTS_H
