//
// Created by backo on 30/5/2024.
//

#include "PinArray.h"
#include <new.h> // Importar el "placement new"

using namespace Pins;


template<class T>
PinArray<T>::PinArray(T* _array, int n) : pinStart(-1), pinEnd(-1), array(_array), size(n) {}

template<class T>
PinArray<T>::PinArray(int pinStart, int pinEnd) : pinStart(pinStart), pinEnd(pinEnd), size(pinEnd - pinStart + 1) {
}

template<class T>
PinArray<T>::PinArray(const PinPair& pins) : PinArray(pins.start, pins.end) {

}

template<class T>
void PinArray<T>::construct(T* ptr, int pin) {
    new(ptr) T(pin);
}

template<class T>
PinArray<T>::~PinArray() {
    for (int i = 0; i < this->size; ++i) {
        this->array[i].~T();
    }

    ::operator delete[](this->array);
}


template<class T>
void PinArray<T>::begin() {

    // Si s'ha de crear l'array, s'ha de fer quan l'objecte ja està construït perquè la funció construct és virtual.
    if (this->array == nullptr) {

        this->array = static_cast<T*>(::operator new[](this->size * sizeof(T)));

        for (int i = 0; i < this->size; ++i) {
            this->construct(this->array + i, this->pinStart + i);
        }
    }

    for (int i = 0; i < this->size; ++i) {
        this->array[i].begin();
    }

}

template<class T>
void PinArray<T>::rangeFunc(void (func)(T*), int start, int end) {
    if (end == -1) {
        end = start;
    }
    //Serial.print("start =");
    //Serial.print(start);
    //Serial.print(" - end =");
    //Serial.println(end);
    T* ptr = this->array + start;
    for (int i = start; i <= end; ++i, ++ptr)
        func(ptr);


}

template<class T>
unsigned int* PinArray<T>::rangeFunc(unsigned int (func)(T*), int start, int end) {
    if (end == -1) {
        end = start;
    }

    auto* result = new unsigned int[end - start + 1];


    T* ptr = this->array + start;
    unsigned int* resPtr = result;

    for (int i = start; i <= end; ++i, ++ptr, ++resPtr) {
        *resPtr = func(ptr);
    }

    return result;
}

template<class U, bool state>
void setLambda(U* out) {
    out->set(state);
}

/*
template<class U>
void onLambda(U* out) {
    dynamic_cast<OutputPin*>(out)->on();
}
template<class U>
void offLambda(U* out) {
    dynamic_cast<OutputPin*>(out)->off();
}
 */

template<class T>
void OutputPinArray<T>::set(bool state, int start, int end) {
    //Serial.print("PinArray set: ");
    //Serial.print(start);
    //Serial.print(" - ");
    //Serial.println(end);
    if (state)
        this->rangeFunc(setLambda<T, true>, start, end);
    else
        this->rangeFunc(setLambda<T, false>, start, end);
}

template<class T>
void OutputPinArray<T>::set(bool state) {
    if (state)
        this->rangeFunc(setLambda<T, true>, 0, this->size - 1);
    else
        this->rangeFunc(setLambda<T, false>, 0, this->size - 1);
}

template<class T>
void OutputPinArray<T>::on(int start, int end) {
    this->set(true, start, end);
}

template<class T>
void OutputPinArray<T>::off(int start, int end) {
    this->set(false, start, end);
}

template<class T>
void OutputPinArray<T>::on() {
    this->set(true);
}

template<class T>
void OutputPinArray<T>::off() {
    this->set(false);
}

template<class U>
unsigned int readLambda(U* in) {
    return in->read();
}

template<class T>
unsigned int* InputPinArrayBase<T>::read(int start, int end) {
    return this->rangeFunc(readLambda, start, end);
}

template<class T>
unsigned int* InputPinArrayBase<T>::read() {
    return this->rangeFunc(readLambda, 0, this->size - 1);
}

void InputPinArray<DigitalIn>::construct(DigitalIn* ptr, int pin) {
    new(ptr) DigitalIn(pin, this->invert, this->debounce, this->pullup);
}

InputPinArray<DigitalIn>::InputPinArray(int pinStart, int pinEnd, bool invert, bool debounce, bool pullup) :
        InputPinArrayBase(pinStart, pinEnd), invert(invert), debounce(debounce), pullup(pullup) {
}

InputPinArray<DigitalIn>::InputPinArray(PinPair pins, bool invert, bool debounce, bool pullup) : InputPinArray(
        pins.start, pins.end, invert, debounce, pullup) {

}

