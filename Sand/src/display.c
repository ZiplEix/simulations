/*
** EPITECH PROJECT, 2023
** simulations [WSL : Debian]
** File description:
** display
*/

#include "sand.h"

void update_window(simulation *simulation)
{
    clear();
    int x = 0;
    int y = 0;

    for (int i = 0; i < simulation->window->y; i++) {
        for (int j = 0; j < simulation->window->x; j++) {
            x = COLS / 2 - simulation->window->x / 2 + j;
            y = LINES / 2 - simulation->window->y / 2 + i;

            attron(COLOR_PAIR(simulation->map[i][j].color));
            // mvprintw(y, x, "%c", simulation->map[i][j].repesentation);
            mvprintw(y, x, "%c", ' ');
            attroff(COLOR_PAIR(simulation->map[i][j].color));

        }
    }

    refresh();
}
