//
// Created by backo on 01/03/25.
//

#ifndef CALCULADORA_ARDUINO_VALUE_H
#define CALCULADORA_ARDUINO_VALUE_H


#define assignExpression(sym) Value& operator sym (int x) { this->_empty = false; this->value sym x; return *this; }

#define operationExpression(sym) int operator sym (int x) const { \
    return this->value sym x;                                     \
}


#include "Arduino.h"

class Value {
private:
    int value = 0;
    bool _empty = true;

public:
    Value(int init, bool empty);

    explicit Value(int init);

    Value() = default;

    bool empty() const;

    operator int() const;

    assignExpression(=);

    assignExpression(+=)

    assignExpression(-=)

    assignExpression(*=)

    assignExpression(/=)

    operationExpression(+)

    operationExpression(-)

    operationExpression(*)

    operationExpression(/)
};

#endif //CALCULADORA_ARDUINO_VALUE_H
