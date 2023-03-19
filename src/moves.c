/*
** EPITECH PROJECT, 2022
** EPITECH [WSL : Ubuntu]
** File description:
** moves
*/

#include "sokoban.h"
#include <unistd.h>

void move_cursor(game_t *game, pl_t *pl)
{
    switch (game->key) {
        case KEY_UP:
            move_vert(game, pl, -1);
            break;
        case KEY_LEFT:
            move_hori(game, pl, -1);
            break;
        case KEY_DOWN:
            move_vert(game, pl, 1);
            break;
        case KEY_RIGHT:
            move_hori(game, pl, 1);
            break;
        default:
            break;
    }
}

void display_map(WINDOW *win, char **map, int nb_rows)
{
    int i = 0;

    clear();
    while (i < nb_rows) {
        mvwaddstr(win , i, 0, map[i]);
        i += 1;
    }
    refresh();
}

int actions(game_t *game, int nb_rows, pl_t *pl)
{
    WINDOW *win;
    int winner = 0;
    if ((win = initscr()) == NULL)
        return EPITECH_ERROR;
    noecho();
    keypad(win, TRUE);
    while (winner != game->nb_holes) {
        display_map(win, game->map, nb_rows);
        game->key = getch();
        if (game->key == 'q' || game->key == 27)
            return 0;
        move_cursor(game, pl);
        winner = win_condition(game);
        if (winner == game->nb_holes) {
            display_map(win, game->map, nb_rows);
            refresh();
            usleep(1000000);
        }
    }
    return 0;
}
