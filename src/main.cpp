#include <Arduino.h>

//#include "avr8-stub.h"

#include "Display.h"
#include "Keypad.h"
#include "SignalLights.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-braces"


using namespace Pins;

Keypad keypad;

Display display;

Calculator calculator(&display);


/*
 * 13,3,22 ok
 *
 */


DigitDisplay digitDisplay(22, 29);
DigitDisplay digitDisplay2(30, 37);
DigitDisplay digitDisplay3(38, 45);
DigitDisplay digitDisplay4(46, 53);

/*
 * 7 x
 * 8 ok
 * A15 ok
 * A14 x
 * A13
 * A12
 * A11
 * A10
 * A9
 * A8
 * A7
 * A6
 * A5
 * A4
 * A3
 * A2
 * A1
 * A0
 */
DigitalIn testBtn(A14, true, true, true);


void setup() {
    //debug_init();
#ifndef DRV_DEBUG_H_
    Serial.begin(9600);
#endif
    //Serial.println(display.input[3] == '\0');
    display.begin();
    calculator.clear();
    //keypad.begin();



    //breakpoint();
    testBtn.begin();
    //testBtn2.begin();

    SignalLights::begin();
    keypad.begin();

    //digitDisplay.begin();
    //digitDisplay2.begin();
    //digitDisplay3.begin();
    //digitDisplay4.begin();
    /*
    for (int i = 7; i < 13; ++i) {
        pinMode(i, INPUT_PULLUP);
    }

    for (int i = 0; i < 10; ++i) {
        pinMode(A0 + i, INPUT_PULLUP);

    }
*/
}
/*
void loop() {


    //digitDisplay.showSymbol(&Symbols::dash);
    //digitDisplay2.showSymbol(&Symbols::dash);
    //digitDisplay3.showSymbol(&Symbols::dash);
    //digitDisplay4.showSymbol(&Symbols::dash);

    delay(100);

    auto state = keypad.read();
    if (state) {
        if (state->type == ButtonInfo::NUMBER) {
            display.append(state->number + '0');
            display.refresh();
        } else if (state->type == ButtonInfo::ACTION) {
            display.del();
            display.refresh();
        }
        Serial.println(*state);
    }

    } //else Serial.println("none");


/*
auto l = keypad.numbers.read();
    for (int i = 0; i < 10; ++i) {
        Serial.print("A");
        Serial.print(i);
        Serial.print(": ");
        Serial.print(digitalRead(A0 + i));
        Serial.print("/");
        Serial.print(l[i]);
        Serial.print("  -  ");
    }
    delete[] l;

    for (int i = 7; i < 13; ++i) {
        Serial.print(i);
        Serial.print(": ");
        Serial.print(digitalRead(i));
        Serial.print("  -  ");
    }

        Serial.println();

}
*/
void loop() {
    const ButtonInfo* state = keypad.read();

    SignalLights::updateAll(&calculator, &display, &keypad);
    switch (state->type) {
        case ButtonInfo::Type::NUMBER:
            calculator.write(state->number);
            break;
        case ButtonInfo::Type::OPERATION:
            calculator.apply(state->operation);
            break;
        case ButtonInfo::Type::ACTION:
            Serial.print("action - ");
            Serial.println(state->action->type);
            state->action->func(&calculator);
            break;
        default: // ButtonCallback::Type::NONE
            break;
    }

    SignalLights::updateAll(&calculator, &display, &keypad);

    delay(30);
}

#pragma clang diagnostic pop