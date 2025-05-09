#pragma clang diagnostic push
#pragma ide diagnostic ignored "google-explicit-constructor"

#include <Arduino.h>

#ifndef CALCULADORA_ARDUINO_OPERATION_H
#define CALCULADORA_ARDUINO_OPERATION_H

struct Operations;

class Operation {
public:
    enum OperationTypes {
        ADDITION,
        SUBTRACTION,
        MULTIPLICATION,
        EXPONENTIATION,
        DIVISION,
        MODULO,
    };
private:
    Operation(OperationTypes type, int (* binary)(int, int));
    Operation(OperationTypes type, int (* unary)(int));
    Operation(OperationTypes type, int (* binary)(int, int), int (* unary)(int));
public:
    OperationTypes type;
    int (*binary)(int, int) = nullptr;
    int (*unary)(int) = nullptr;

    friend ::Operations;
};


#endif //CALCULADORA_ARDUINO_OPERATION_H

#pragma clang diagnostic pop