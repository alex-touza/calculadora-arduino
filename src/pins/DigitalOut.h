#ifndef CASA_DOMOTICA_SORTIDADIGITAL_H
#define CASA_DOMOTICA_SORTIDADIGITAL_H

#include <Arduino.h>
#include "Pin.h"

namespace Pins {
    class DigitalOut : public OutputPin {
    public:
        using OutputPin::OutputPin;

        void begin() override;

        void on() override;

        void off() override;

        /*
        Encendre la sortida durant un temps determinat.
        */
        void on(unsigned long t);

        /*
        Apagar la sortida durant un temps determinat.
        */
        void off(unsigned long t);

        /*
        Assignar la sortida a un valor.
        Valors de tipus bool són convertits a int.
        */
        void set(unsigned int value) override;

        /*
        Assignar la sortida a un valor durant un temps determinat.
        Valors de tipus bool són convertits a int.
        */
        void set(unsigned int estat, unsigned long t);
        /*
        Encendre la sortida si està apagada, o apagar-la
        si està encesa. Retorna l'estat final.
        */
        unsigned int toggle();

        /*
        Interval de 10 microsegons.
        */
        void pulseOut();

    };
}


#endif