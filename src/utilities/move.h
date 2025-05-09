//
// Created by backo on 17/04/25.
//

#ifndef CALCULADORA_ARDUINO_MOVE_H
#define CALCULADORA_ARDUINO_MOVE_H

template<typename T>
struct remove_reference {
    using type = T;
};

template<typename T>
struct remove_reference<T&> {
    using type = T;
};

template<typename T>
struct remove_reference<T&&> {
    using type = T;
};

// move implementation
template<typename T>
constexpr typename remove_reference<T>::type&& move(T&& t) noexcept {
    return static_cast<typename remove_reference<T>::type&&>(t);
}
#endif //CALCULADORA_ARDUINO_MOVE_H
