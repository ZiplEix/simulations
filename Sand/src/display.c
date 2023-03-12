/*
** EPITECH PROJECT, 2023
** simulations [WSL : Debian]
** File description:
** display
*/

#include "sand.h"

void update_window(simulation *simulation)
{
    wclear(simulation->window->win);

    for (int i = 0; i < simulation->window->y; i++) {
        for (int j = 0; j < simulation->window->x; j++) {

            wattron(simulation->window->win, COLOR_PAIR(simulation->map[i][j].color));
            wmove(simulation->window->win, i, j); // déplacer le curseur dans la fenêtre
            waddch(simulation->window->win, simulation->map[i][j].repesentation);
            wattroff(simulation->window->win, COLOR_PAIR(simulation->map[i][j].color));

        }
    }

    wrefresh(simulation->window->win);
}
