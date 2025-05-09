//
// Created by backo on 03/03/25.
//

#include "Keypad.h"
#include <new>


Button Keypad::buttonsOperations[]{
        Button(A13, Button::OPERATION, &Operations::addition),
        Button(A14, Button::OPERATION, &Operations::subtraction),
        Button(A15, Button::OPERATION, &Operations::multiplication, &Operations::exponentiation),
        Button(7, Button::OPERATION, &Operations::division, &Operations::modulo),
        //Button(20, Button::OPERATION, &Operations::sign),
};

ButtonInfo* Keypad::buttonsInfoNumbers[]{};

Button Keypad::buttonsActions[]{
        Button(A10, Button::ACTION, &Actions::del),
        Button(A11, Button::ACTION, &Actions::clear),
        Button(A12, Button::ACTION, &Actions::calculate),
        Button(53, Button::ACTION, &Actions::reset),
        Button(52, Button::ACTION, &Actions::sign),
};

void Keypad::begin() {
    for (auto& button : Keypad::buttonsActions) {
        button.begin();
    }
    for (auto& button : Keypad::buttonsOperations) {
        button.begin();
    }
    this->numbers.begin();
}

Keypad::Keypad() : numbers(Keypad::numbersPins, Keypad::invert, Keypad::debounce, Keypad::pullup) {
    static_assert(Keypad::numbersPins.count() == 10, "Keypad: Nombre de pins erroni");

    for (int i = 0; i < 10; ++i) {
        *(Keypad::buttonsInfoNumbers + i) = new ButtonInfo(Button::NUMBER, i);
    }
}

template<int Length>
const ButtonInfo* Keypad::iterateInput(const unsigned int* ptr, ButtonInfo* (* func)(int)) {
    const ButtonInfo* buttonInfo = nullptr;
    for (int i = 0; i < Length; ++i) {
        if (ptr[i]) {
            buttonInfo = func(i);
            break;
        }
    }

    delete[] ptr;
    return buttonInfo;
}

template<int Length>
const ButtonInfo* Keypad::iterateInput(Button array[Length]) {
    const ButtonInfo* buttonInfo = nullptr;

    for (int i = 0; i < Length; ++i) {
        const ButtonInfo* thisButtonInfo = array[i].read();

        if (thisButtonInfo) {
            buttonInfo = thisButtonInfo;
            break;
        }
    }

    return buttonInfo;
}


/*
 * Ordre de preferència:
 * 1. accions
 * 2. nombres
 * 3. operations
 */
const ButtonInfo* Keypad::read() {


    if (const ButtonInfo* actionsState = Keypad::iterateInput<Keypad::actionsCount>(Keypad::buttonsActions)) {
        this->lastPress = Button::ACTION;
        return actionsState;
    }

    if (const ButtonInfo* numbersState = Keypad::iterateInput<10>(this->numbers.read(), [](int index) {
        return Keypad::buttonsInfoNumbers[index];
    })) {
        this->lastPress = Button::NUMBER;
        return numbersState;
    }

    if (const ButtonInfo* operationsState = Keypad::iterateInput<::operationsCount>(Keypad::buttonsOperations)) {
        this->lastPress = Button::OPERATION;
        return operationsState;
    }

    this->lastPress = Button::NONE;
    return nullptr;

}

