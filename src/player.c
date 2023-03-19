/*
** EPITECH PROJECT, 2022
** EPITECH [WSL : Ubuntu]
** File description:
** player
*/

#include "struct.h"

char **replace_pl(char **cpy, int i)
{
    for (int j = 0; cpy[i][j] != '\0'; j += 1) {
        if (cpy[i][j] == 'P')
            cpy[i][j] = ' ';
    }

    return cpy;
}

char **replace_box(char **cpy, int i)
{
    for (int j = 0; cpy[i][j] != '\0'; j += 1) {
        if (cpy[i][j] == 'X')
            cpy[i][j] = ' ';
    }

    return cpy;
}

char **replace_elt(char **cpy)
{
    for (int i = 0; cpy[i] != NULL; i += 2) {
        cpy = replace_pl(cpy, i);
        cpy = replace_box(cpy, i);
    }

    return cpy;
}

void place_pl(game_t *game, pl_t *pl, int x, int y)
{
    if (game->map[y][x] == 'P') {
        pl->y = y;
        pl->x = x;
    }
}

void find_pl(game_t *game, pl_t *pl)
{
    for (int y = 0; game->map[y] != NULL; y += 1) {
        for (int x = 0; game->map[y][x] != '\0'; x += 1) {
            place_pl(game, pl, x, y);
        }
    }
}
