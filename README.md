# Arduino Calculator

This is a repository that contains the code for a Calculator made with Arduino and its paper (in Catalan).

The calculator is based on seven segment displays and an array of buttons with several functions.

This project was made as an optional task in the high school subject Technology and Engineering.

## Characteristics

### Features

This calculator is equipped with everything you'd expect from a standard calculator:


- **Sophisticated yet simple calculation procedures** inspired by actual calculators.
- **Calculate power and modulo**, apart from usual addition, subtraction, product, division and sign
- **Lights that indicate the state of the calculator**: whether there's a number saved in memory, whether an operation is active, etc.
- **Adapts to any number of digits** thanks to generic programming.


### Limitations

I'm only human, after all.

- **No support for decimals** because that would require using floating point numbers, which I'm very uncomfortable with.
- **Limited amount of digits** due to not using a dedicated encoder or processor for the seven segment displays.

## Structure

- `diagrams` - Class and flux diagrams for the project.
- `paper` - Typst code for the paper, written in Catalan.
- `src` - Source code, in C++.

## Requirements

- Arduino Mega
- PlatformIO
- C++ compiler

## Similar projects

I've done other projects with Arduino and PlatformIO:

- [Casa domòtica](https://github.com/alex-touza/casa-domotica)
- [Simulador de màquina de Turing](https://github.com/alex-touza/simulador-maquina-turing)