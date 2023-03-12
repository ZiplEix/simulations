/*
** ZiplEix PROJECT, 2023
** simulations [WSL : Debian]
** File description:
** sand
*/

#ifndef SAND_H_
#define SAND_H_

    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <string.h>
    #include <time.h>
    #include <ncurses.h>
    #include <stdbool.h>
    #include <locale.h>

    #include "struct.h"

    #define WIDTH 20
    #define HEIGHT 20

    #define RANDNUM(min, max) \
        ((rand() % (int)(((max) + 1) - (min))) + (min))

    // materials
    material init_void(void);
    material init_wall(void);
    material init_sand(void);

    // simulation
    void update_window(simulation *simulation);
    void set_up_window(void);
    simulation *init_simulation(char *filename);
    material **init_map(simulation *simu);
    int get_map(const char* filename, simulation *simu);

#endif /* !SAND_H_ */
