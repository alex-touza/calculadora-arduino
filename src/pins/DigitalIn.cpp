#include "DigitalIn.h"
#include "Arduino.h"

Pins::DigitalIn::DigitalIn(int pin, const bool invert, const bool debounce, const bool pullup)
        : InputPin(pin), debounce(debounce), invert(invert), pullup(pullup) {}

void Pins::DigitalIn::begin() {
    pinMode(this->pin, this->pullup ? INPUT_PULLUP : INPUT);
    this->active = false;
}

unsigned long Pins::DigitalIn::pulseIn(bool state) {
    this->value = 0;
    return ::pulseIn(this->pin, state);
}

unsigned int Pins::DigitalIn::read() {
    unsigned int _value = digitalRead(this->pin);
    if (this->invert) _value = !_value;

    if (_value) Serial.println("1");
    if (this->debounce) {
        if (_value) {
            _value = 0;
            this->active = true;

        } else if (this->active) {
            _value = 1;
            this->active = false;
            Serial.println("debounced");
        }

    }

    return this->value = _value;
}

Pins::DigitalIn::~DigitalIn() = default;

/*
void CDPins::EntradaDigital::attachInterrupt(InterruptModes mode, void (* callback)()) {
    ::attachInterrupt(digitalPinToInterrupt(this->pin), callback, mode);
}

template<typename T>
void CDPins::EntradaDigital::attachInterrupt(InterruptModes mode, void (* callback)(T), T* arg) {
    ::attachInterruptArg(digitalPinToInterrupt(this->pin), callback, arg, mode);
}*/
