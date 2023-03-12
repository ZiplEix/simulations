/*
** ZiplEix PROJECT, 2023
** simulations [WSL : Debian]
** File description:
** init_window
*/

#include "sand.h"

void set_up_window(void)
{
    // Initialisation de ncurses
    initscr();
    cbreak();
    noecho();
    curs_set(0);

    start_color();

    // Initialisation des couleurs
    init_pair(0, COLOR_BLACK, COLOR_BLACK);
    init_pair(1, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(2, COLOR_RED, COLOR_RED);
    init_pair(3, COLOR_GREEN, COLOR_GREEN);
    init_pair(4, COLOR_BLUE, COLOR_BLUE);
    init_pair(5, COLOR_MAGENTA, COLOR_MAGENTA);

    // Configurer la fenêtre pour nodelay
    nodelay(stdscr, TRUE);
}
