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
    #include <stdbool.h>
    #include <locale.h>

    #include "PXEG.h"

    #define RANDNUM(min, max) \
        ((rand() % (int)(((max) + 1) - (min))) + (min))

#endif /* !SAND_H_ */
