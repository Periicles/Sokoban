/*
** EPITECH PROJECT, 2022
** EPITECH
** File description:
** my_sokoban
*/

#include "struct.h"
#include "sokoban.h"
#include <stdlib.h>

void end_game(game_t *game)
{
    endwin();
    delwin(game->win);
}

char *create_map(game_t *game, char *str2)
{
    char const *filepath = str2;

    if (filepath == NULL)
        return (char *)EPITECH_ERROR;

    char *str = get_map(filepath);
    game->nb_rows = get_rows(str);
    game->map = malloc(sizeof(char *) * (game->nb_rows + 1));
    game->map[game->nb_rows] = NULL;
    game->cpy = malloc(sizeof(char *) * (game->nb_rows + 1));
    game->cpy[game->nb_rows] = NULL;

    return str;
}

int do_map(game_t *game, char *str)
{
    alloc_map(game->map, str);
    alloc_map(game->cpy, str);
    init_map(game->map, str);
    init_map(game->cpy, str);
    if (map_errors(game) == 84)
        return EPITECH_ERROR;

    return 0;
}

int main(int ac, char **av)
{
    if (check_errors(ac, av) == 84)
        return EPITECH_ERROR;

    pl_t *pl = malloc(sizeof(pl_t));
    game_t *game = malloc(sizeof(game_t));
    if (pl == NULL || game == NULL)
        return EPITECH_ERROR;

    char *str = create_map(game, av[1]);
    if (do_map(game, str) == 84)
        return EPITECH_ERROR;

    replace_elt(game->cpy);
    find_pl(game, pl);
    actions(game, game->nb_rows, pl);
    end_game(game);

    return 0;
}
