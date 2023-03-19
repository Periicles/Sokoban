/*
** EPITECH PROJECT, 2023
** boxnholes
** File description:
** boxnholes
*/

#include "struct.h"
#include "sokoban.h"

void count(game_t *game, int i, int j)
{

    if (game->map[i][j] == 'X')
        game->nb_crates += 1;
    if (game->cpy[i][j] == 'O')
        game->nb_holes += 1;
}

game_t *find_hole(game_t *game)
{
    game->nb_holes = 0;
    game->nb_crates = 0;

    for (int i = 0; game->map[i] != NULL; i += 1) {
        for (int j = 0; game->map[i][j] != '\0'; j += 1) {
            count(game, i, j);
        }
    }
    return game;
}
