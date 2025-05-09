//
// Created by backo on 28/02/25.
//

#include "Operations.h"

#define operation(op) [](int a, int b) { return a op b; }

const Operation Operations::addition(Operation::OperationTypes::ADDITION, operation(+), [](int a) { return a; });

const Operation Operations::subtraction(Operation::OperationTypes::SUBTRACTION, operation(-), [](int a) { return -a; });

const Operation Operations::multiplication(Operation::OperationTypes::MULTIPLICATION, operation(*),
                                           [](int a) { return a * a; });

// pre: b >= 0
const Operation Operations::exponentiation(Operation::OperationTypes::EXPONENTIATION, [](int a, int b) {
    if (b == 0) return 1;

    int r = a;

    for (int i = 1; i < b; ++i) {
        r *= a;
    }

    return r;
});

const Operation Operations::division(Operation::OperationTypes::DIVISION, operation(/));

// pre: b != 0
const Operation Operations::modulo(Operation::OperationTypes::MODULO, [](int a, int b) {
    // Fer que l'operador % funcioni igual que a Python (floored division)
    if (a == 0) return 0;
    int m = a % b;
    return (a < 0) == (b < 0) ? m : m + b;
});

//const Operation Operations::sign(Operation::OperationTypes::SIGN, [](int a) { return -a; });



