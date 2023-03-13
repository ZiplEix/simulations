/*
** EPITECH PROJECT, 2023
** simulations [WSL : Debian]
** File description:
** main
*/

#include "sand.h"

bool compare_color(PXEG_Color color1, PXEG_Color color2)
{
    if (color1.r == color2.r && color1.g == color2.g && color1.b == color2.b && color1.a == color2.a)
        return true;
    return false;
}

void update_simulation(PXEG_Window *window, PXEG_Buffers *buffers)
{
    PXEG_SetPixel(window, buffers, 40, 0, PXGE_COLOR_YELLOW);

    for (int i = window->pixel_height ; i >= 0; i--) {
        for (int j = 0; j < window->pixel_width; j++) {
            if (compare_color(PXEG_GetPixel(buffers, j, i), PXGE_COLOR_YELLOW) == true) {
                if (i + 1 < window->pixel_height && compare_color(PXEG_GetPixel(buffers, j, i + 1), PXGE_COLOR_BLACK) == true) {
                    PXEG_SetPixel(window, buffers, j, i + 1, PXGE_COLOR_YELLOW);
                    PXEG_SetPixel(window, buffers, j, i, PXGE_COLOR_BLACK);
                } else if (i + 1 < window->pixel_height && compare_color(PXEG_GetPixel(buffers, j, i + 1), PXGE_COLOR_BLACK) != true) {
                    if (j + 1 < window->pixel_width && compare_color(PXEG_GetPixel(buffers, j + 1, i + 1), PXGE_COLOR_BLACK) == true) {
                        PXEG_SetPixel(window, buffers, j + 1, i + 1, PXGE_COLOR_YELLOW);
                        PXEG_SetPixel(window, buffers, j, i, PXGE_COLOR_BLACK);
                    } else if (j - 1 >= 0 && compare_color(PXEG_GetPixel(buffers, j - 1, i + 1), PXGE_COLOR_BLACK) == true) {
                        PXEG_SetPixel(window, buffers, j - 1, i + 1, PXGE_COLOR_YELLOW);
                        PXEG_SetPixel(window, buffers, j, i, PXGE_COLOR_BLACK);
                    }
                }
            }
        }
    }
}

void sand(PXEG_Window *window, PXEG_Buffers *buffers)
{
    bool paused = false;

    while (PXEG_Run()) {
        int x, y;
        PXEG_Mouse_position(window, &x, &y);

        if (paused == false) {
            update_simulation(window, buffers);
        }

        if (PXEG_IsKeyPressed(SDL_SCANCODE_SPACE)) {
            paused = !paused;
        }
        PXEG_Update(window, buffers);
    }
}

int main(int argc, char *argv[])
{
    PXEG_Window window;
    PXEG_Buffers *buffers = PXEG_init("Pixel Engine", &window, 800, 600, 80, 60);

    // fill the buffer with black
    for (int i = 0; i < window.pixel_height; i++) {
        for (int j = 0; j < window.pixel_width; j++) {
            PXEG_SetPixel(&window, buffers, j, i, PXGE_COLOR_BLACK);
        }
    }

    // set a wall in blue
    for (int i = 10; i < window.pixel_width - 10; i++) {
        PXEG_SetPixel(&window, buffers, i, 50, PXGE_COLOR_BLUE);
    }

    sand(&window, buffers);

    PXEG_destroy(&window, buffers);

    return 0;
}
