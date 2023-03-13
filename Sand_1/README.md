# Sand 1

My first of sand falling and spreading simulation.

## Introduction

This is my first simulation of sand falling and spreading on a surface. It is written in C and uses the NCurses library to display the simulation.

## Installation

### Pre-requisites

- A C compiler (by default `gcc` is used but you can change ir in the `Makefile` line 12)
- [The NCurses library](https://www.cyberciti.biz/faq/linux-install-ncurses-library-headers-on-debian-ubuntu-centos-fedora/)

### Compilation

To compile the program, run the following command:

    make

## the algorythm

The algorythm is very simple. It is based on the fact that sand will fall down if there is nothing under it. If there is something under it, it will spread on the side if there is nothing.

![Algorythm demonstration GIF](../assets/Sand_Algorythm.gif)

## Usage

To run the program, run the following command:

    ./sand_simulation [your/map/file]

## Map file

If no map file is specified, the program will use the default map file. (maps/default)

You can create your own map file. The map file must be a text file with the following format:

    x[width]\n
    y[height]\n
    [map]

Where:

- `x[width]` is the width of the map
- `y[height]` is the height of the map
- `[map]` is the map itself

The map must fit the width and height specified, otherwise the program will stop and let you know why it stopped.

Map caractreres are:

- `~` for void
- `*` for sand
- `#` for wall

Be careful, a infinite dans generator is set in `(x/2, 0)`

## Controls

- `q` to quit the program (you can quit if the programm is paused)
- `" "` (space) to pause the simulation

## Configuration

You can configure the program by editing the `config.conf` file.

The default `config.conf` file is self-explanatory.

Be careful, the program will only do some basic chcecks on the configuration file. If you mess up the configuration file, the program will probably crash or not work as expected.
