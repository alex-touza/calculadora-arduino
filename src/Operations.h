//
// Created by backo on 28/02/25.
//

#ifndef CALCULADORA_ARDUINO_OPERATIONS_H
#define CALCULADORA_ARDUINO_OPERATIONS_H


#include "Operation.h"


constexpr int operationsCount = 4;


struct Operations {
public:
    static const Operation addition;
    static const Operation subtraction;
    static const Operation multiplication;
    static const Operation exponentiation;
    static const Operation division;
    static const Operation modulo;
    //static const Operation sign;
};





#endif //CALCULADORA_ARDUINO_OPERATIONS_H
