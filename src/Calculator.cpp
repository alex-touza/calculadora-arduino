//
// Created by backo on 28/02/25.
//

#include "Calculator.h"

Calculator::Calculator(Display* display) : display(display) {
}


void Calculator::write(int n) {
    if (abs(n) > 9) {
#ifndef DRV_DEBUG_H_
        //Serial.println("ERROR (Calculator): Intentant escriure un nombre de més d'una xifra");
#endif
    }

    if (this->next) {
        this->memo = this->value;

        this->display->clear();
        this->display->append((this->value = n) + '0');

        this->next = false;
        //this->lastOperation = nullptr;
    } else {
        this->value *= 10;
        this->value += n;

        this->display->append(n + '0');
    }

    this->display->refresh();

}

void Calculator::del() {
    if (this->display->state == Display::RESULT) {
        this->clear();
        return;
    }
    this->value /= 10;

    if (this->value == 0) this->display->sign = Display::POSITIVE;

    this->display->del();
    this->display->refresh();
}

void Calculator::apply(const Operation* operation) {
    this->display->refresh();
    if (operation->binary == nullptr) {
        this->value = operation->unary(this->value);
    } else if (this->activeOperation == operation) {
        this->activeOperation = nullptr;
        this->next = false;
    } else {
        this->activeOperation = operation;
        this->next = true;
    }
}

void Calculator::calculate() {

    if (this->activeOperation == nullptr) {
        if (this->lastOperation == nullptr) goto end;

        this->value = this->lastOperation->operation->binary(this->value, this->lastOperation->operand);
    } else {
        if (((this->activeOperation->type == Operation::DIVISION || this->activeOperation->type == Operation::MODULO) &&
             this->value == 0) || (this->activeOperation->type == Operation::EXPONENTIATION && this->value < 0)) {
            this->display->error();
            this->activeOperation = nullptr;
            return;
        }

        this->lastOperation = new OperationAction{this->activeOperation, this->value};
        if (this->memo.empty()) {
            if (this->activeOperation->unary == nullptr) goto end;

            this->value = this->activeOperation->unary(this->value);
        } else {
            this->value = this->activeOperation->binary(this->memo, this->value);
        }
        this->memo = Value();

    }

    if (abs(this->value) > Display::maxValue) {
        this->value = 0;
        this->memo=Value();
        this->display->clear();
        this->activeOperation = nullptr;
        this->display->flash();
        return;
    }

    this->next = true;

    this->display->set(this->value);

    end:
    this->display->refresh();
    this->activeOperation = nullptr;
}

void Calculator::clear() {
    this->value = Value(0);
    this->display->clear();
    this->display->refresh();
}


void Calculator::reset() {
    this->memo = Value();
    this->clear();
}

void Calculator::toggleSign() {
    this->next = false;
    this->display->sign = this->display->sign == Display::POSITIVE ? Display::NEGATIVE : Display::POSITIVE;
    this->value = -value;
    this->display->refresh();
}

