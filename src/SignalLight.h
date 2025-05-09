//
// Created by backo on 12/04/25.
//

#ifndef CALCULADORA_ARDUINO_SIGNALLIGHT_H
#define CALCULADORA_ARDUINO_SIGNALLIGHT_H

#include "pins/DigitalOut.h"
#include "Display.h"

class Calculator;

class Keypad;

class SignalLight : Pins::DigitalOut {
public:
    enum Color {
        WHITE,
        BLUE,
        GREEN,
        YELLOW,
        RED
    };


    bool (* funcCalculator)(const Calculator*) = nullptr;

    bool (* funcDisplay)(const Display*) = nullptr;

    bool (* funcKeypad)(const Keypad*) = nullptr;

    Display::State displayState = Display::State::CALC;

    Color color;
    String id;

    SignalLight(String id, int pin, Color color, bool (* funcCalculator)(const Calculator*));

    SignalLight(String id, int pin, Color color, bool (* funcDisplay)(const Display*));

    SignalLight(String id, int pin, Color color, Display::State displayState);

    SignalLight(String id, int pin, Color color, bool (* funcKeypad)(const Keypad*));

    void update(const Calculator* calculator, const Display* display, const Keypad* keypad);

    using Pins::DigitalOut::begin;
    //using Pins::DigitalOut::on;
    //using Pins::DigitalOut::off;


};

#endif //CALCULADORA_ARDUINO_SIGNALLIGHT_H
