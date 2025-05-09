//
// Created by backo on 04/03/25.
//

#ifndef CALCULADORA_ARDUINO_BUTTON_H
#define CALCULADORA_ARDUINO_BUTTON_H

#include "Operation.h"
#include "pins/DigitalIn.h"
#include "Calculator.h"
#include "Action.h"

using namespace Pins;


struct ButtonInfo {

    enum Type {
        OPERATION,
        ACTION,
        NUMBER,
        NONE
    };

    const Type type;

    const union {
        const Operation* operation;
        const Action* action;
        const int number;
    };



    ButtonInfo(Type type, const Action* action);

    ButtonInfo(Type type, const Operation* operation);

    ButtonInfo(Type type, int number);

    operator String() const;
};


class Button : public ButtonInfo {
private:
    DigitalIn pin;

    unsigned long lastPress = 0;
public:
    using ButtonInfo::Type;
    static const bool debounce = true;
    static const bool invert = true;
    static const bool pullup = true;

    static const unsigned long doublePressTime = 1000;

    const ButtonInfo* doublePress;


    Button(int pin, Type type, const Action* action, const Action* secondaryAction = nullptr);

    Button(int pin, Type type, const Operation* operation, const Operation* secondaryOperation = nullptr);

    void begin();

    /**
     * @returns nullptr si no s'ha premut el botó o un punter a una funció que executa l'acció
     */
    const ButtonInfo* read();;

    ~Button();
};


#endif //CALCULADORA_ARDUINO_BUTTON_H
