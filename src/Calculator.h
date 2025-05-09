//
// Created by backo on 28/02/25.
//

#ifndef CALCULADORA_ARDUINO_CALCULATOR_H
#define CALCULADORA_ARDUINO_CALCULATOR_H


#include "Display.h"
#include "Operation.h"
#include "Value.h"


class Calculator {
private:
    Display* display;
public:
    // si la següent tecla ha de començar a escriure el següent nombre
    bool next = false;

    // TODO rename
    struct OperationAction {
        const Operation* operation;
        int operand;
    };

    Value memo;
    Value value;

    const Operation* activeOperation = nullptr;
    const OperationAction* lastOperation = nullptr;

    explicit Calculator(Display* display);

    void write(int n);

    void del();

    void clear();

    void apply(const Operation* operation);

    void calculate();


    void reset();

    void toggleSign();
};


#endif //CALCULADORA_ARDUINO_CALCULATOR_H
