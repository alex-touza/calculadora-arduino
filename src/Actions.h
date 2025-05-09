//
// Created by backo on 17/04/25.
//

#ifndef CALCULADORA_ARDUINO_ACTIONS_H
#define CALCULADORA_ARDUINO_ACTIONS_H

#include "Action.h"

struct Actions {
public:
    static const Action reset;
    static const Action clear;
    static const Action del;
    static const Action calculate;
    static const Action sign;
};


#endif //CALCULADORA_ARDUINO_ACTIONS_H
