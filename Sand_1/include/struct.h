/*
** ZiplEix PROJECT, 2023
** simulations [WSL : Debian]
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

typedef enum colors_e {
    BLACK,
    YELLOW,
    RED,
    GREEN,
    BLUE,
    MAGENTA,
} colors;

typedef enum type_e {
    VOID,
    WALL,
    SAND
} type;

typedef struct window_t {
    WINDOW *win;
    int x;
    int y;
} window;

typedef struct material_t {
    type type;
    colors color;

    char repesentation;

    int x;
    int y;

    bool is_falling;

    void (*move)(struct material_t*);
} material;

typedef struct simulation_t {
    int is_paused;
    int last_user_input;

    // the time between each update (in ms)
    int time_gap;

    char *map_path;
    char **char_map;
    material **map;

    int cycle;
    int falling_entity_frequency;

    window *window;
} simulation;

#endif /* !STRUCT_H_ */
