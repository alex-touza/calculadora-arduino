//
// Created by backo on 18/04/25.
//

#include "SymbolStrings.h"

const SymbolString SymbolStrings::error{
        Symbol{LEFT, TOP, MIDDLE, BOTTOM},                  // E
        Symbol{LEFT_BOTTOM, MIDDLE},                        // r
        Symbol{LEFT_BOTTOM, MIDDLE},                        // r
        Symbol{LEFT_BOTTOM, MIDDLE, RIGHT_BOTTOM, BOTTOM},  // o
        Symbol{LEFT_BOTTOM, MIDDLE},                        // r
};

const SymbolString SymbolStrings::hola{
        Symbol{LEFT, RIGHT, MIDDLE},        // H
        Symbol{LEFT, RIGHT, BOTTOM, TOP},   // O
        Symbol{LEFT, BOTTOM},               // L
        Symbol{LEFT, RIGHT, MIDDLE, TOP}    // A
};