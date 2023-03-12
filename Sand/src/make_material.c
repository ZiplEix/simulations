/*
** EPITECH PROJECT, 2023
** simulations [WSL : Debian]
** File description:
** make_material
*/

#include "sand.h"

material init_void()
{
    material voids;
    voids.type = VOID;
    voids.color = MAGENTA;
    voids.repesentation = '~';
    voids.x = 0;
    voids.y = 0;
    voids.is_falling = false;
    voids.move = NULL;
    return voids;
}

material init_wall()
{
    material wall;
    wall.type = WALL;
    wall.color = BLUE;
    wall.repesentation = '#';
    wall.x = 0;
    wall.y = 0;
    wall.is_falling = false;
    wall.move = NULL;
    return wall;
}

material init_sand()
{
    material sand;
    sand.type = SAND;
    sand.color = YELLOW;
    sand.repesentation = '*';
    sand.x = 0;
    sand.y = 0;
    sand.is_falling = true;
    sand.move = NULL;
    return sand;
}