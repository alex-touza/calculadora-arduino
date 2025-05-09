//
// Created by backo on 04/03/25.
//

#include "Button.h"

ButtonInfo::ButtonInfo(ButtonInfo::Type type, const Action* action) : type(type),
        action(action) {}

ButtonInfo::ButtonInfo(ButtonInfo::Type type, const Operation* operation) : type(type), operation(operation) {}

ButtonInfo::ButtonInfo(ButtonInfo::Type type, int number) : type(type), number(number) {
}

ButtonInfo::operator String() const {
    String string("Type: ");

    switch (this->type) {
        case OPERATION:
            string += "OPERATION - ";
            string += this->operation->type;
            return string;
        case ACTION:
            string += "ACTION - ";
            string += this->action->type;
            return string;
        case NUMBER:
            string += "NUMBER - ";
            string += this->number;
            return string;
        case NONE:
            return "NONE";
    }

}


Button::Button(int pin, Button::Type type, const Action* action, const Action* secondaryAction) : ButtonInfo(type,
                                                                                                             action),
        pin(pin, Button::invert,
            Button::debounce,
            Button::pullup), doublePress(secondaryAction ==
                                         nullptr ? nullptr : new ButtonInfo(ACTION, secondaryAction)) {}

Button::Button(int pin, Button::Type type, const Operation* operation, const Operation* secondaryOperation) : ButtonInfo(type, operation),
        pin(pin, Button::invert, Button::debounce, Button::pullup),  doublePress(secondaryOperation ==
                                                                                 nullptr ? nullptr : new ButtonInfo(OPERATION, secondaryOperation)){}

void Button::begin() {
    this->pin.begin();
}

const ButtonInfo* Button::read() {

    if (this->pin.read()) {
        const ButtonInfo* ptr = this->doublePress && this->lastPress != 0 && (millis() - this->lastPress < doublePressTime)
                                ? this->doublePress : dynamic_cast<const ButtonInfo*>(this);
        this->lastPress = millis();
        return ptr;
    } else return nullptr;
}


Button::~Button() {
    delete doublePress;
}

