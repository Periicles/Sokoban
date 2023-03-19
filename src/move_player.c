/*
** EPITECH PROJECT, 2022
** EPITECH [WSL : Ubuntu]
** File description:
** simple_move
*/

#include "struct.h"
#include "sokoban.h"

int check_circle(game_t *game, pl_t *pl)
{
    if ((game->cpy[pl->y][pl->x]) == 'O') {
        return 0;
    }

    return 1;
}

int move_box_vert(game_t *game, pl_t *pl, int alpha)
{
    if ((game->map[pl->y + alpha][pl->x]) == 'X' &&
    ((game->map[pl->y + (2 * alpha)][pl->x]) != '#') &&
    ((game->map[pl->y + (2 * alpha)][pl->x]) != 'X')) {
        game->map[pl->y + (2 * alpha)][pl->x] = game->map[pl->y + alpha][pl->x];
    } else if ((game->map[pl->y + alpha][pl->x]) == 'X' &&
    ((game->map[pl->y + (2 * alpha)][pl->x]) == '#' ||
    (game->map[pl->y + (2 * alpha)][pl->x]) == 'X')) {
        return EPITECH_ERROR;
    }

    return 0;
}

int move_vert(game_t *game, pl_t *pl, int alpha)
{
    if (move_box_vert(game, pl, alpha) == 84)
        return EPITECH_ERROR;

    if ((game->map[pl->y + alpha][pl->x]) != '#') {
        game->map[pl->y + alpha][pl->x] = game->map[pl->y][pl->x];
        if (check_circle(game, pl) == 0) {
            game->map[pl->y][pl->x] = 'O';
            pl->y = pl->y + alpha;
            return 0;
        }
        game->map[pl->y][pl->x] = ' ';
        pl->y = pl->y + alpha;
        return 0;
    }

    return EPITECH_ERROR;
}

int move_box_hori(game_t *game, pl_t *pl, int alpha)
{
    if ((game->map[pl->y][pl->x + alpha]) == 'X' &&
    ((game->map[pl->y] [pl->x + (2 * alpha)]) != '#') &&
    (game->map[pl->y][pl->x + (2 * alpha)]) != 'X')
        game->map[pl->y][pl->x + (2 * alpha)] = game->map[pl->y][pl->x + alpha];
    else if ((game->map[pl->y][pl->x + alpha]) == 'X' &&
    ((game->map[pl->y][pl->x + (2 * alpha)]) == '#' ||
    (game->map[pl->y][pl->x + (2 * alpha)]) == 'X'))
        return EPITECH_ERROR;

    return 0;
}

int move_hori(game_t *game, pl_t *pl, int alpha)
{
    if (move_box_hori(game, pl, alpha) == 84)
        return EPITECH_ERROR;

    if ((game->map[pl->y][pl->x + alpha]) != '#') {
        game->map[pl->y][pl->x + alpha] = game->map[pl->y][pl->x];
        if (check_circle(game, pl) == 0) {
            game->map[pl->y][pl->x] = 'O';
            pl->x = pl->x + alpha;
            return 0;
        }
        game->map[pl->y][pl->x] = ' ';
        pl->x = pl->x + alpha;
        return 0;
    }

    return EPITECH_ERROR;
}
