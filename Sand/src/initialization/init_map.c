/*
** EPITECH PROJECT, 2023
** simulations [WSL : Debian]
** File description:
** init_map
*/


#include "sand.h"

static void print_map(simulation *simu, material **map)
{
    for (int i = 0; i < simu->window->y; i++) {
        for (int j = 0; j < simu->window->x; j++) {
            printf("%c", map[i][j].repesentation);
        }
        printf("\n");
    }
}

material **init_map(simulation *simu)
{
    material **map = calloc(simu->window->y, sizeof(material *));

    for (int i = 0; i < simu->window->y; i++) {
        map[i] = calloc(simu->window->x, sizeof(material));
        for (int j = 0; j < simu->window->x; j++) {
            switch (simu->char_map[i][j]) {
                case '~':
                    map[i][j] = init_void();
                    break;
                case '#':
                    map[i][j] = init_wall();
                    break;
                case '*':
                    map[i][j] = init_sand();
                    break;
                default:
                    break;
            }
        }
    }

    return map;
}
