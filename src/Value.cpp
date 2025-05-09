//
// Created by backo on 01/03/25.
//

#include "Value.h"

Value::operator int() const { // NOLINT(*-explicit-constructor)
    if (this->_empty) Serial.print("Error (Calculator::Value): Lectura d'un valor buit");
    return this->value;
}

Value::Value(int init) : Value(init, false) {}

Value::Value(int init, bool empty) : value(init), _empty(empty) {}

bool Value::empty() const {
    return this->_empty;
}
