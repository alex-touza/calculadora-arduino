//
// Created by backo on 12/04/25.
//

#include "SignalLight.h"

SignalLight::SignalLight(String id, int pin, SignalLight::Color color, bool (* funcCalculator)(const Calculator*)) : Pins::DigitalOut(pin),
        funcCalculator(funcCalculator),
        color(color),
        id(id) {}

SignalLight::SignalLight(String id, int pin, SignalLight::Color color, bool (* funcDisplay)(const Display*)) : Pins::DigitalOut(pin),
        funcDisplay(funcDisplay),
        color(color),
        id(id) {}

SignalLight::SignalLight(String id, int pin, SignalLight::Color color, Display::State displayState) : Pins::DigitalOut(pin),
        displayState(displayState),
        color(color),
        id(id){

}

SignalLight::SignalLight(String id, int pin, SignalLight::Color color, bool (* funcKeypad)(const Keypad*)) : Pins::DigitalOut(pin),
        funcKeypad(funcKeypad),
        color(color),
        id(id) {}

void SignalLight::update(const Calculator* calculator, const Display* display, const Keypad* keypad) {
    if (this->funcCalculator) {
        this->set(this->funcCalculator(calculator));
    } else if (this->funcDisplay) {
        this->set(this->funcDisplay(display));
    } else if (this->funcKeypad) {
        this->set(this->funcKeypad(keypad));
    } else {
        this->set(this->displayState == display->state);
    }
}
