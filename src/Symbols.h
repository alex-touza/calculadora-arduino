#pragma clang diagnostic push
#pragma ide diagnostic ignored "bugprone-dynamic-static-initializers"
//
// Created by backo on 28/02/25.
//

#ifndef PANTALLA_DE_7_SEGMENTS_SYMBOLS_H
#define PANTALLA_DE_7_SEGMENTS_SYMBOLS_H

#include "Symbol.h"

struct Symbols {
    static const SymbolWithValue<bool> all;
    static const SymbolWithValue<bool> none;
    static const SymbolWithValue<int> numbers[10];

    static const SymbolWithValue<char> dash;
    static const SymbolWithValue<char> symbols[];

    static const SymbolWithValue<bool>* empty;
};


#endif //PANTALLA_DE_7_SEGMENTS_SYMBOLS_H

#pragma clang diagnostic pop