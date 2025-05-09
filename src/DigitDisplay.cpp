//
// Created by backo on 18/02/25.
//

#include "DigitDisplay.h"

DigitDisplay::DigitDisplay(byte pinStart, byte pinEnd) {
    if (pinEnd - pinStart + 1 == DigitDisplay::pinsNumber) {
        this->pinArray = new Pins::OutputPinArray<Pins::DigitalOut>(pinStart, pinEnd);
    } else {
        //Serial.println("ERROR (DigitDisplay): Nombre de pins erroni");
    }
}

void DigitDisplay::begin() {
    this->pinArray->begin();
#ifndef DRV_DEBUG_H_
    //Serial.println("ok");
#endif
}

void DigitDisplay::on(Segment segment) {
    //Serial.println("Turn on segment at ");
    //Serial.println(static_cast<int>(segment));
    this->pinArray->off(static_cast<int>(segment)); // Apagar un pin permet la sortida del corrent d'un ànode
}

void DigitDisplay::clear() {
    this->current = Symbols::empty;
    this->pinArray->on(); // Encendre tots els pins bloqueja la sortida dels ànodes de la pantalla
    //Serial.println("Cleared");
}

void DigitDisplay::showSymbol(const Symbol* symbol) {
    this->clear();
    if (symbol->isEmpty()) return;

    this->current = symbol;

    int i = 0;
    for (auto it = symbol->segments; i < symbol->size; ++it, ++i) {
        this->on(*it);
    }
}
