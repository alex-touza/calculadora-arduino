//
// Created by backo on 28/02/25.
//

#ifndef CALCULADORA_ARDUINO_SYMBOLSTRING_H
#define CALCULADORA_ARDUINO_SYMBOLSTRING_H


#include "Symbol.h"

class SymbolString : protected VariadicAggregation<Symbol> {
public:
    using VariadicAggregation<Symbol>::VariadicAggregation;
    using VariadicAggregation<Symbol>::size;
    const Symbol* symbols = VariadicAggregation<Symbol>::array;
};
#endif //CALCULADORA_ARDUINO_SYMBOLSTRING_H
