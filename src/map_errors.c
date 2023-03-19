/*
** EPITECH PROJECT, 2023
** PSU [WSL: Ubuntu]
** File description:
** map_errors
*/

#include "struct.h"
#include "sokoban.h"

int valid_char(char c)
{
    if ((c != ' ') && (c != '#') && (c != 'O') && (c != 'P') && (c != 'X') &&
    (c != '\n'))
        return EPITECH_ERROR;

    return 0;
}

int map_is_valid(char **map)
{
    int valid = 0;

    for (int i = 0; map[i] != NULL; i += 1) {
        for (int j = 0; map[i][j] != '\0'; j += 1) {
            valid += valid_char(map[i][j]);
        }
    }

    return valid;
}

int is_player(int player, char c)
{
    if (c == 'P') {
        player += 1;
    }

    return player;
}

int player_exists(game_t *game)
{
    int player = 0;

    for (int i = 0; game->map[i] != NULL; i += 1) {
        for (int j = 0; game->map[i][j] != '\0'; j += 1) {
            player = is_player(player, game->map[i][j]);
        }
    }
    if (player != 1)
        return EPITECH_ERROR;

    return 0;
}

int map_errors(game_t *game)
{
    game = find_hole(game);

    if (game->nb_crates < game->nb_holes)
        return EPITECH_ERROR;
    if (player_exists(game) == 84)
        return EPITECH_ERROR;
    if (map_is_valid(game->map) == 84)
        return EPITECH_ERROR;

    return 0;
}
