//
// Created by backo on 04/03/25.
//

#ifndef CALCULADORA_ARDUINO_STATICVARIADICAGGREGATION_H
#define CALCULADORA_ARDUINO_STATICVARIADICAGGREGATION_H


template<typename T, int N>
class StaticVariadicAggregation {
protected:
    // Constructor amb paràmetres variàdics
    template<typename ...U>
    StaticVariadicAggregation(U... args) : array{new T[N]{static_cast<T>(args)...}} {};
public:
    const T array[N];
};



#endif //CALCULADORA_ARDUINO_STATICVARIADICAGGREGATION_H
