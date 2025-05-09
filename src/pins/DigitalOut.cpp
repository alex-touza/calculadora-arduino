#include "DigitalOut.h"
#include "Arduino.h"

void Pins::DigitalOut::begin() {
    pinMode(this->pin, OUTPUT);
}

void Pins::DigitalOut::on() {
    this->set(HIGH);
}

void Pins::DigitalOut::off() {
    this->set(LOW);
}

void Pins::DigitalOut::on(unsigned long t) {
    this->set(HIGH, t);
}

void Pins::DigitalOut::off(unsigned long t) {
    this->set(LOW, t);
}

void Pins::DigitalOut::set(unsigned int value) {
    digitalWrite(this->pin, value);
    this->value = value;
}

void Pins::DigitalOut::set(unsigned int estat, unsigned long t) {
    this->set(estat);
    delay(t);
    this->set(!estat);
}

unsigned int Pins::DigitalOut::toggle() {
    this->set(!this->value);
    return this->value;
}

void Pins::DigitalOut::pulseOut() {
    this->on();
    delayMicroseconds(10);
    this->off();
}