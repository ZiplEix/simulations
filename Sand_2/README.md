# Sand 2

My second sand falling and spreading simulation. With a graphical interface.

## Introduction

This is my second simulation of sand falling and spreading on a surface. It is written in C and uses the [SPXE](https://github.com/LogicEu/spxe) library to display the simulation.

    I don't made this code, I just adapted an exemple of the SPXE librairy to my needs.

I won't use the librairie anymore because it leak a lot and use a lot of memory, I will make my own graphical interface.

## Installation

### Pre-requisites

- A C compiler (by default `gcc` is used but you can change ir in the `Makefile` line 12)
- The [SPXE](https://github.com/LogicEu/spxe) library and his dependencies

### Compilation

To compile the program, run the following command:

    make

## Usage

To run the program, run the following command:

    ./sand_simulation [x] [y]

Where `x` and `y` are the size of the simulation pixel buffer.

`x` and `y` are optional.

If only `x` is specified, the simulation will be a square of size `x`.


## Controls

- `q` to quit the program (you can quit if the programm is paused)
- `" "` (space) to pause the simulation

## Configuration

This programme is ony configurate in the source code.
