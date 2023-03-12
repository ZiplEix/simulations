/*
** ZiplEix PROJECT, 2023
** simulations [WSL : Debian]
** File description:
** get_&_parse_map
*/

#include "sand.h"

static void print_map(simulation *simu)
{
    for (int i = 0; i < simu->window->y; i++) {
        for (int j = 0; j < simu->window->x; j++) {
            printf("%c", simu->char_map[i][j]);
        }
        printf("\n");
    }
}

int get_map(const char* filename, simulation *simu)
{
    FILE* fp = NULL;

    if (filename == NULL) {
        fp = fopen("maps/default_map", "r");
    } else {
        fp = fopen(filename, "r");
    }

    if (fp == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return 1;
    }

    // Lecture des deux premières lignes
    fscanf(fp, "x%d\ny%d\n", &simu->window->x, &simu->window->y);

    // Allocation de la mémoire pour le contenu du fichier
    simu->char_map = calloc(simu->window->y + 1, sizeof(char *));
    for (int i = 0; i < simu->window->y; i++) {
        simu->char_map[i] = calloc(simu->window->x + 1, sizeof(char));
        fscanf(fp, "%s\n", simu->char_map[i]);

        // Vérification de la longueur de la ligne
        if (strlen(simu->char_map[i]) != simu->window->x) {
            printf("Erreur: la ligne %d ne contient pas le bon nombre de caractères.\n", i+3);
            return 1;
        }
    }
    simu->char_map[simu->window->y] = NULL;

    // Vérification du nombre de lignes non vides
    int count = 0;
    while (simu->char_map[count]) {
        count++;
    }

    if (count != simu->window->y) {
        printf("Erreur: le nombre de lignes n'est pas le bon.\nIl y a %d lignes au lieu de %d.\n", count, simu->window->y);
        return 1;
    }

    // printf("Fichier lu avec succès : \n");
    // print_map(simu);

    // exit(0);

    fclose(fp);
    return 0;
}
