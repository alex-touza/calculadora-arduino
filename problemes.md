- Problema 1. La pantalla de 7 segments fa el que vol: quan es vol encendre un segment, se n'encenen diversos.
    - Mètode de depuració: Ús de Serial.print() per trobar els valors de les variables que intervenen en l'execució.
      S'observa que la variable `end` té un valor de 255, quan hauria de ser igual a `start`, ja que s'encén un sol
      segment.
    - Causa: Al codi de les classes PinArray, s'estava fent servir -1 com a valor per defecte del pin, però aquest es
      guarda en un `byte`, que és un enter sense signe de 8 bits.
    - Solució: Per poder tenir un valor que indiqui que `end` no s'ha establert, s'ha de canviar totes les instàncies de
      `byte` per `int`.
- Problema 2. El debug no funciona.
    - Mètode de depuració: Amb l'ajut de ChatGPT, es prova d'executar la comanda de depuració des del terminal.
    - Causa: El programa que controla la depuració, GDB, es basa en una versió anterior de `ncurses` a la qual tinc
      instal·lada al meu ordinador.
    - Solució: Instal·lar el paquet `ncurses-compat-libs` ja fa que el debug funcioni tant a la terminal com a la
      interfície del CLion.
- Problema 3. Els botons del números del 4 al 9 no funcionen.
  - Mètode de depuració: Nombrosos prints.
  - Causa: No s'estaven creant tots els objectes dels pins. 3 hores per adonar-se d'això. Em cago en tot.
    ```c++
    for (int i = 0; i < operationsCount; ++i) {
    *(Keypad::buttonsInfoNumbers + i) = new ButtonInfo(Button::NUMBER, i);
    }
    ```