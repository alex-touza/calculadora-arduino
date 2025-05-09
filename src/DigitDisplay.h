//
// Created by backo on 18/02/25.
//

#ifndef PANTALLA_DE_7_SEGMENTS_SEGMENTSDISPLAY_H
#define PANTALLA_DE_7_SEGMENTS_SEGMENTSDISPLAY_H

#include "pins/PinArray.h"
#include "Symbol.h"
#include "Symbols.h"


class DigitDisplay {
private:
    Pins::OutputPinArray<Pins::DigitalOut>* pinArray;

public:
    static constexpr byte pinsNumber = 8;
    const Symbol* current = &Symbols::none;

    DigitDisplay(byte pinStart, byte pinEnd);

    void begin();

    void clear();

    void showSymbol(const Symbol* symbol);

    void on(Segment segment);
};


#endif //PANTALLA_DE_7_SEGMENTS_SEGMENTSDISPLAY_H
