//
// Created by backo on 17/04/25.
//

#ifndef CALCULADORA_ARDUINO_ACTION_H
#define CALCULADORA_ARDUINO_ACTION_H

#include "Calculator.h"


class Action {
public:
    enum ActionTypes {
        RESET,
        CLEAR,
        DEL,
        CALCULATE,
        SIGN
    };
    ActionTypes type;

    void (* func)(Calculator*);


};


#endif //CALCULADORA_ARDUINO_ACTION_H
