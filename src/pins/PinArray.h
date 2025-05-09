//
// Created by backo on 30/5/2024.
//

#ifndef SIMULADOR_MAQUINA_TURING_PINARRAY_H
#define SIMULADOR_MAQUINA_TURING_PINARRAY_H

#include "DigitalIn.h"
#include "DigitalOut.h"
#include "PinPair.h"

namespace Pins {

    template<class T>
    class PinArray {
    protected:
        T* array = nullptr;

        virtual void construct(T*, int);

    public:
        const int pinStart;
        const int pinEnd;
        const int size;


        /*
         * Crear objecte a partir d'una llista de pins
         */
        PinArray(T*, int);

        /*
         * Crear objecte a partir d'un rang de pins [pinStart, pinEnd]
         */
        PinArray(int, int);

        PinArray(const PinPair&); // NOLINT(*-explicit-constructor)

        void begin();

        /*
         * Executar una funció per a cada pin en un rang [a,b] amb 0 <= a < b < size, tots dos inclosos.
         *
         * Quan hi ha paràmetres de l'estil (int start, int end),
         * si s'assigna `start` però no `end`, aquest últim valor
         * serà igual a `start`. D'aquesta forma, no es repeteix el
         * valor si només es vol actuar per a un sol element.
         */
        void rangeFunc(void (func)(T*), int, int = -1);


        /*
         * El mateix que la funció anterior, però retorna en una array dels valors retornats de cada funció.
         *
         * Cal fer servir `delete[]` per no causar una fuita de memòria.
         */
        [[nodiscard]] unsigned int* rangeFunc(unsigned int (func)(T*), int = 0, int = -1);

        ~PinArray();

    };


    template<class T>
    class OutputPinArray : protected PinArray<T> {
    public:
        using PinArray<T>::PinArray;
        using PinArray<T>::begin;
        using PinArray<T>::size;

        void set(bool, int, int = -1);

        void set(bool);

        void on(int, int = -1);

        void off(int, int = -1);

        void on();

        void off();

    };


    template<class T>
    class InputPinArrayBase : protected PinArray<T> {
    protected:
        using PinArray<T>::PinArray; // Evitar que es pugui crear un objecte a partir d'aquesta classe
    public:
        using PinArray<T>::begin;
        using PinArray<T>::size;

        /**
         * Cal fer servir `delete[]` per no causar una fuita de memòria.
         */
        [[nodiscard]] unsigned int* read(int, int = -1);

        [[nodiscard]] unsigned int* read();
    };



    template<class T>
    class InputPinArray : public InputPinArrayBase<T> {
    public:
        using InputPinArrayBase<T>::InputPinArrayBase;  // Inherit constructors
    };


    template<>
    class InputPinArray<DigitalIn> : public InputPinArrayBase<DigitalIn> {
    protected:
        void construct(DigitalIn* ptr, int pin) override;

    public:
        const bool invert;
        const bool debounce;
        const bool pullup;

        InputPinArray<DigitalIn>(int pinStart, int pinEnd, bool invert, bool debounce, bool pullup);

        InputPinArray<DigitalIn>(PinPair pins, bool invert, bool debounce, bool pullup);
    };


    template
    class OutputPinArray<DigitalOut>;

    // No hauria de ser necessari, però el compilador es queixa, si no es posa
    template
    class PinArray<DigitalIn>;

    // El mateix, el mateix InputPinArray ja té una especialització per a DigitalIn
    template
    class InputPinArrayBase<DigitalIn>;

    template
    class PinArray<DigitalOut>;
    // template class PinArray<AnalogIn>;
    // template class PinArray<AnalogOut>;

} // TMPins

#endif //SIMULADOR_MAQUINA_TURING_PINARRAY_H
