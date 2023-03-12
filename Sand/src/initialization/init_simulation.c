/*
** EPITECH PROJECT, 2023
** simulations [WSL : Debian]
** File description:
** init_simulation
*/

#include "sand.h"

window *init_window(simulation *simu)
{
    window *win = malloc(sizeof(window));
    win->win = newwin(win->y, win->x, 0, 0);
    return win;
}

simulation *init_simulation(char *filename)
{
    simulation *simu = malloc(sizeof(simulation));

    simu->is_paused = false;
    simu->last_user_input = 0;
    simu->window = init_window(simu);
    if (get_map(filename, simu) == 1)
        exit(84);
    simu->map = init_map(simu);
    simu->time_gap = 100;
    simu->cycle = 0;

    return simu;
}
