//
// Created by backo on 28/02/25.
//

#ifndef CALCULADORA_ARDUINO_VARIADICAGGREGATION_H
#define CALCULADORA_ARDUINO_VARIADICAGGREGATION_H

template<typename T>
class VariadicAggregation {
public:
    // Constructor amb paràmetres variàdics
    template<typename ...U>
    VariadicAggregation(U... args) : size(sizeof...(args)), array{new T[sizeof...(args)]{static_cast<T>(args)...}} {};
    const int size;
    const T* array;
};


#endif //CALCULADORA_ARDUINO_VARIADICAGGREGATION_H
