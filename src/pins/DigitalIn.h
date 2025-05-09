#ifndef EntradaDigital_h
#define EntradaDigital_h

#include <Arduino.h>
#include "Pin.h"
/*
enum InterruptModes {
    SIGNALRISING = RISING,
    SIGNALFALLING = FALLING,
};
*/

namespace Pins {
    class DigitalIn : public InputPin {
    public:
        using InputPin::InputPin;

        virtual ~DigitalIn();

        /**
        *
        * @param debounce Només retornar 1 quan s'hagi deixat de rebre senyal.
        * @param invert Invertir el senyal d'entrada.
        */
        DigitalIn(int, bool invert, bool debounce, bool pullup);

        const bool debounce = false;
        const bool invert = false;
        const bool pullup = false;

        bool active = false;

        void begin() override;

        unsigned int read() override;

        /*
        Equivalent a la funció integrada corresponent amb un
        interval de 10 microsegons.
        */
        unsigned long pulseIn(bool state = HIGH);

        /*
        void attachInterrupt(InterruptModes mode, void (*callback)());

        template<typename T>
        void attachInterrupt(InterruptModes mode, void (*callback)(T), T* arg);
        */
    };

}
#endif