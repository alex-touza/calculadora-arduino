//
// Created by backo on 22/02/25.
//

#ifndef PANTALLA_DE_7_SEGMENTS_SYMBOL_H
#define PANTALLA_DE_7_SEGMENTS_SYMBOL_H

#include <Arduino.h>
#include "utilities/VariadicAggregation.h"


enum Segment {
    MIDDLE = 0,
    LEFT_TOP = 1,
    TOP = 2,
    RIGHT_TOP = 3,
    LEFT_BOTTOM = 4,
    BOTTOM = 5,
    RIGHT_BOTTOM = 6,
    POINT = 7
};
#define LEFT LEFT_BOTTOM, LEFT_TOP
#define RIGHT RIGHT_BOTTOM, RIGHT_TOP

struct Symbols;

struct SymbolStrings;

class Symbol : protected VariadicAggregation<Segment> {
protected:
    using VariadicAggregation<Segment>::VariadicAggregation;
public:
    using VariadicAggregation<Segment>::size;
    const Segment* segments = VariadicAggregation<Segment>::array;

    bool isEmpty() const;

    friend Symbols; // Permetre a Symbols construir els objectes Symbol
    friend SymbolStrings;
};

template<typename ValueType>
class SymbolWithValue : public Symbol {
protected:
    template<typename ...T>
    SymbolWithValue(ValueType value, T... args) : value(value), Symbol(args...) {
    };
public:
    const ValueType value;

    friend Symbols;
};

#endif //PANTALLA_DE_7_SEGMENTS_SYMBOL_H
