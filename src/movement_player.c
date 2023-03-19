/*
** EPITECH PROJECT, 2122
** EPITECH [WSL : Ubuntu]
** File description:
** movement
*/

#include "struct.h"
#include "sokoban.h"

int move_u(game_t *game, pl_t *pl)
{
    move_vert(game, pl, -1);

    return 0;
}

int move_d(game_t *game, pl_t *pl)
{
    move_vert(game, pl, 1);

    return 0;
}

int move_l(game_t *game, pl_t *pl)
{
    move_hori(game, pl, -1);

    return 0;
}

int move_r(game_t *game, pl_t *pl)
{
    move_hori(game, pl, 1);

    return 0;
}
