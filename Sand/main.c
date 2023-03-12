/*
** ZiplEix PROJECT, 2023
** simulations [WSL : Debian]
** File description:
** main
*/

#include "sand.h"

int handle_input(simulation *simulation)
{
    simulation->last_user_input = getch();
    if (simulation->last_user_input == 'q') {
        return 1;
    }

    if (simulation->last_user_input == ' ') {
        simulation->is_paused = !simulation->is_paused;
    }

    if (simulation->is_paused) {
        nodelay(stdscr, FALSE);
        while (getch() != ' ') {}
        simulation->is_paused = !simulation->is_paused;
        nodelay(stdscr, TRUE);
    } else {
        napms(simulation->time_gap);
    }
    return 0;
}

void update_simulation(simulation *simulation)
{
    // TODO
}

void sand(char **argv)
{
    simulation *simulation = init_simulation(argv[1]);

    set_up_window();

    while (1) {
        if (simulation->is_paused == false) {
            update_simulation(simulation);
        }
        update_window(simulation);
        if (handle_input(simulation) == 1)
            break;
    }

    endwin();
}

int main(int argc, char **argv)
{
    sand(argv);
    return 0;
}
