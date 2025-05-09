//
// Created by backo on 28/02/25.
//

#include "Symbols.h"

const SymbolWithValue<bool> Symbols::none(false);

const SymbolWithValue<bool>* Symbols::empty = &Symbols::none;

const SymbolWithValue<bool> Symbols::all(true, TOP, MIDDLE, BOTTOM, LEFT, RIGHT);

const SymbolWithValue<int> Symbols::numbers[10]{
        {0, TOP, LEFT, RIGHT, BOTTOM},
        {1, RIGHT},
        {2, TOP, RIGHT_TOP, MIDDLE, LEFT_BOTTOM, BOTTOM},
        {3, TOP, MIDDLE, BOTTOM, RIGHT},
        {4, LEFT_TOP, MIDDLE, RIGHT},
        {5, TOP, LEFT_TOP, MIDDLE, RIGHT_BOTTOM, BOTTOM},
        {6, TOP, BOTTOM, MIDDLE, LEFT, RIGHT_BOTTOM},
        {7, TOP, RIGHT, LEFT_TOP},
        {8, TOP, MIDDLE, BOTTOM, LEFT, RIGHT},
        {9, TOP, BOTTOM, MIDDLE, RIGHT, LEFT_TOP}
};

const SymbolWithValue<char> Symbols::dash('-', MIDDLE);

const SymbolWithValue<char> Symbols::symbols[]{
        dash
};