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

int get_conf(simulation *simu)
{
    FILE *file = fopen("./config.conf", "r");
    if (!file) {
        perror("fopen");
        return -1;
    }

    char line[100];
    int line_number = 0;

    while (fgets(line, sizeof(line), file)) {
        line_number++;

        if (line[0] == '#' || line[0] == '\n') {
            // Ignore comments and empty lines
            continue;
        }

        char *key = strtok(line, "=");
        char *value = strtok(NULL, "=");

        if (!key || !value) {
            fprintf(stderr, "Configuration file : Error on line %d: Invalid syntax\n", line_number);
            return -1;
        }

        if (strcmp(key, "TIME_GAP") == 0) {
            simu->time_gap = atoi(value);
        } else if (strcmp(key, "FALLING_ENTITY_FREQUENCY") == 0) {
            simu->falling_entity_frequency = atoi(value);
        } else {
            fprintf(stderr, "Configuration file : Error on line %d: Unknown key \"%s\"\n", line_number, key);
            return -1;
        }
    }

    fclose(file);
    return 0;
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
    simu->cycle = 0;
    if (get_conf(simu) == -1)
        exit(84);

    return simu;
}
