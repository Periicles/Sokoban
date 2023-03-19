/*
** EPITECH PROJECT, 2023
** win_lose
** File description:
** win_lose
*/

#include "sokoban.h"
#include "struct.h"

int verif(game_t *game, int i , int j)
{
    if ((game->cpy[i][j] == 'O') && (game->map[i][j] == 'X')) {
        return 1;
    }

    return 0;
}

int win_condition(game_t *game)
{
    int winner = 0;

    for (int i = 0; game->cpy[i] != NULL; i += 1){
        for (int j = 0; game->cpy[i][j]; j += 1)
            winner += verif(game, i, j);
    }

    return winner;
}
