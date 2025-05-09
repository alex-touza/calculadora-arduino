//
// Created by backo on 03/03/25.
//

#ifndef CALCULADORA_ARDUINO_KEYPAD_H
#define CALCULADORA_ARDUINO_KEYPAD_H
#include <Arduino.h>

#include "pins/PinArray.h"
#include "pins/DigitalIn.h"
#include "Operation.h"
#include "Operations.h"
#include "Button.h"
#include "Actions.h"

using namespace Pins;


class Keypad {
public: //private:
    static constexpr PinPair numbersPins{A0, A9};
    InputPinArray<DigitalIn> numbers;

    static ButtonInfo* buttonsInfoNumbers[10];

    static Button buttonsOperations[operationsCount];

    static constexpr int actionsCount = 5;

    static Button buttonsActions[actionsCount];

    static constexpr bool debounce = true;
    static constexpr bool invert = true;
    static constexpr bool pullup = true;

    template<int Length>
    static const ButtonInfo* iterateInput(const unsigned int* ptr, ButtonInfo* (*func)(int index));


    template<int Length>
    static const ButtonInfo* iterateInput(Button array[Length]);

public:

    ButtonInfo::Type lastPress = ButtonInfo::NONE;

    Keypad();

    void begin();

    /**
     *
     * @return Un punter a la informació del botó premut. No s'ha de fer servir `delete`, ja que és un punter a l'objecte del botó mateix.
     */
    const ButtonInfo* read();

};


#endif //CALCULADORA_ARDUINO_KEYPAD_H
