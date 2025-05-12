//
// Created by backo on 28/02/25.
//

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-braces"
#ifndef PANTALLA_DE_7_SEGMENTS_DISPLAY_H
#define PANTALLA_DE_7_SEGMENTS_DISPLAY_H

#include "DigitDisplay.h"
#include "SymbolStrings.h"
#include "pins/PinSet.h"

class Display {
public:
    static constexpr int Size = 5;
    static constexpr long blinkTime = 60;
    static const int maxValue;
    enum State {
        CALC,
        RESULT,
        ERROR,
        MESSAGE
    };
    enum Sign {
        POSITIVE,
        NEGATIVE
    };
private:
    static constexpr PinGroups pins{8, 47, DigitDisplay::pinsNumber};
     //static const PinSet pins;

    DigitDisplay* digits[Size]{};

    char input[Size]{};
    int inputLength = 0;
    //Symbols* message;


    void showSymbolAll(const Symbol* symbol);

    void showString(const SymbolString* symbolString);

    void clearAll();

    void hello();

    void printInput();
protected:
    /**
     * @return Referència al caràcter a l'índex donat.
     */
    inline char& getChar(int index) noexcept {
        return this->input[Display::Size - 2 - index];
    }

public:
    State state = CALC;
    Sign sign;

    Display();

    void begin();

    void refresh();

    void append(char c);

    void del();

    void clear();

    void set(int number);

    void error();

    void flash();

    ~Display();

};


#endif //PANTALLA_DE_7_SEGMENTS_DISPLAY_H

#pragma clang diagnostic pop