//
// Created by backo on 28/02/25.
//

#include "Display.h"
#include <new.h>
#include "utilities/placement_new.h"

//const PinSet Display::pins{PinPair{22, 53}, PinPair{18, 21}, PinPair{8, 11}}

const int Display::maxValue = ([](int size) {
    int r = 1;

    for (int i = 1; i < size; ++i) {
        r *= 10;
    }

    return r - 1;
})(Display::Size);

void Display::printInput() {
    Serial.print("Input(");
    Serial.print(this->inputLength);
    Serial.print("): |");
    Serial.print(this->input);
    Serial.println("|");
    for (int i = 0; i < Size - 1; ++i) {
        Serial.print(i);
        Serial.print(" - ");
        Serial.println(this->getChar(i));
    }
}

Display::Display() {
    static_assert(Display::pins.count() % DigitDisplay::pinsNumber == 0 &&
                  Display::pins.count() / DigitDisplay::pinsNumber == Display::Size, "Display: Nombre de pins erroni");

    memset(this->input, ' ', Display::Size - 1);
    this->input[Size - 1] = '\0';

    //this->digits = static_cast<DigitDisplay*>(::operator new[](Size * sizeof(DigitDisplay)));

    int i = 0;
    for (auto& ptr : this->digits) {
        ptr = new DigitDisplay(Display::pins.start + DigitDisplay::pinsNumber * i,
                               Display::pins.start + DigitDisplay::pinsNumber * (i + 1) - 1);
        ++i;
    }
}

void Display::showSymbolAll(const Symbol* symbol) {
    for (auto& digitDisplay : this->digits) {
        digitDisplay->showSymbol(symbol);
    }
}

void Display::clearAll() {
    this->showSymbolAll(&Symbols::none);
}


void Display::begin() {
    for (auto& digitDisplay : this->digits) {
        digitDisplay->begin();
    }

    this->hello();
}

void Display::hello() {
    this->showSymbolAll(&Symbols::all);
    delay(500);
    this->clearAll();
    delay(700);
    this->showString(&SymbolStrings::hola);


    if (SymbolStrings::hola.size < Display::Size) {
        Segment segmentsCycle[]{
                TOP, LEFT_TOP, LEFT_BOTTOM, BOTTOM, RIGHT_BOTTOM, RIGHT_TOP
        };
        for (int i = 0; i < 18; ++i) {
            this->digits[Display::Size - 1]->clear();
            this->digits[Display::Size - 1]->on(segmentsCycle[i % 6]);
            delay(100);
        }
    } else delay(12 * 100);
    this->clear();
    this->refresh();
}


void Display::refresh() {

    /*
    Symbol* symbols[Size];
    if (this->state == MESSAGE) {


    }
     */

    this->clearAll();
    delay(Display::blinkTime);

    this->digits[0]->showSymbol(this->sign == NEGATIVE ? dynamic_cast<const Symbol*>(&Symbols::dash)
                                                       : dynamic_cast<const Symbol*>(&Symbols::none));

    auto inputIt = this->input;
    Serial.print("Input(");
    Serial.print(this->inputLength);
    Serial.print("): |");
    Serial.print(this->input);
    Serial.println("|");

    // Iterar des del segon dígit cap a l'últim
    for (int i = 1; i < Size; ++i, ++inputIt) {
        auto digitIt = this->digits[i];

        switch (*inputIt) {
            case ' ':
                digitIt->clear();
                break;
            case '-':
                digitIt->showSymbol(&Symbols::dash);
                break;
            default:
                digitIt->showSymbol(Symbols::numbers + (*inputIt - '0'));
        }
    }

}


void Display::flash() {
    this->showSymbolAll(&Symbols::all);
    delay(Display::blinkTime * 3);
    this->clearAll();
    delay(Display::blinkTime);
    this->refresh();
}


void Display::append(char c) {
    if (this->inputLength == Size - 1) this->flash();
    else {
        this->state = CALC;

        // Moure tots els caràcters cap a l'esquerra.
        for (int i = this->inputLength - 1; i >= 0; --i) {
            this->getChar(i + 1) = this->getChar(i);
            //this->input[Size - 3 - i] = this->input[Size - 2 - i];
        }
        /*
        for (auto it = this->firstChar; it != this->input + Size - 2 - this->inputLength; --it) {
            *(it - 1) =*it;
        }
        */
        this->getChar(0) = c;

        if (this->inputLength != 0 || c != '0') ++this->inputLength;
        printInput();
    }
}


void Display::del() {
    if (this->inputLength == 0) {
        this->flash();
        return;
    }
    Serial.println("Del");
    printInput();
    --this->inputLength;
    // Moure tots els caràcters cap a la dreta.
    for (int i = 0; i < this->inputLength; ++i) {
        this->getChar(i) = this->getChar(i + 1);
    }

    // Eliminar últim caràcter
    this->getChar(this->inputLength) = ' ';

    if (this->inputLength == 0) this->getChar(0) = '0';
    printInput();
    //this->input[this->inputLength - 1] = ' ';
}


void Display::clear() {
    this->sign = POSITIVE;
    this->state = CALC;
    for (char& c : this->input) {
        if (c != '\0') c = ' ';
    }

    this->inputLength = 0;
    this->getChar(0) = '0';

}


void Display::set(int number) {
    Serial.print("Set result: ");
    Serial.println(number);
    if (number < 0) {
        this->sign = NEGATIVE;
        number *= -1;
    } else this->sign = POSITIVE;

    this->state = RESULT;

    char* ptr = &this->getChar(0);

    bool empty = false;
    // Iterar des de l'últim caràcter fins al segon
    do {
        *(ptr--) = empty ? ' ' : (number % 10 + '0');

        number /= 10;
        if (!empty && number == 0) empty = true;
    } while (ptr >= this->input);


}

void Display::error() {
    this->state = ERROR;
    this->showString(&SymbolStrings::error);
}


Display::~Display() {
    for (auto& digit : this->digits) {
        delete digit;
    }

    //::operator delete[](this->digits);
}

void Display::showString(const SymbolString* symbolString) {
    if (symbolString->size > Display::Size) {
        Serial.print("Error (Display): symbolString massa llarg (");
        Serial.print(symbolString->size);
        Serial.println(")");
        return;
    }
    this->clearAll();

    for (int i = 0; i < symbolString->size; ++i) {
        this->digits[i]->showSymbol(&symbolString->symbols[i]);
    }
}


