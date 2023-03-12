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
    if (simulation->cycle % 2 == 0) {
        simulation->map[0][25] = init_sand();
    }

    for (int i = simulation->window->y - 1; i >= 0; i--) {
        for (int j = 0; j < simulation->window->x; j++) {
            if (simulation->map[i][j].type == SAND) {
                if (i + 1 < simulation->window->y && simulation->map[i + 1][j].type == VOID) {
                    simulation->map[i + 1][j] = init_sand();
                    simulation->map[i][j] = init_void();
                } else if (i + 1 < simulation->window->y && simulation->map[i + 1][j].type != VOID) {
                    if (j + 1 < simulation->window->x && simulation->map[i + 1][j + 1].type == VOID) {
                        simulation->map[i + 1][j + 1] = init_sand();
                        simulation->map[i][j] = init_void();
                    } else if (j - 1 >= 0 && simulation->map[i + 1][j - 1].type == VOID) {
                        simulation->map[i + 1][j - 1] = init_sand();
                        simulation->map[i][j] = init_void();
                    }
                }
            }
        }
    }
}

void sand(char **argv)
{
    simulation *simulation = init_simulation(argv[1]);

    set_up_window();

    while (1) {
        if (simulation->is_paused == false) {
            update_simulation(simulation);
            simulation->cycle++;
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
