//
// Created by backo on 28/02/25.
//

#include "Operation.h"

Operation::Operation(OperationTypes type, int (* binary)(int, int)) : type(type), binary(binary) {}

Operation::Operation(OperationTypes type, int (* unary)(int)) : type(type), unary(unary) {}

Operation::Operation(OperationTypes type, int (* binary)(int, int), int (* unary)(int)) : type(type), binary(binary), unary(unary) {}
