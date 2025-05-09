//
// Created by backo on 17/04/25.
//

#include "Actions.h"

const Action Actions::del{Action::DEL, [](Calculator* calculator) {
    Serial.println("del");
    calculator->del();
}};

const Action Actions::reset{Action::RESET, [](Calculator* calculator) {
    calculator->reset();
}};

const Action Actions::clear{Action::CLEAR, [](Calculator* calculator) {
    calculator->clear();
}};

const Action Actions::calculate{Action::CALCULATE, [](Calculator* calculator) {
    calculator->calculate();
}};

const Action Actions::sign{Action::SIGN, [](Calculator* calculator) {
    if (calculator->value != 0) calculator->toggleSign();
}};