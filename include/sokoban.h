/*
** EPITECH PROJECT, 2022
** EPITECH [WSL : Ubuntu]
** File description:
** sokoban
*/

#include "my.h"
#include "struct.h"

#ifndef SOKOBAN_H_
    #define SOKOBAN_H_

    #define EPITECH_ERROR 84;

    int help(void);
    int check_errors(int ac, char **av);
    int map_errors(game_t *game);

    char *create_map(game_t *game, char *str);

    void move_cursor(game_t *game, pl_t *pl);
    int actions(game_t *game, int nb_rows, pl_t *pl);

    int get_rows(char *str);
    char *get_map(char const *filepath);
    void alloc_map(char **map, char *str);
    void init_map(char **map, char *str);

    char **replace_elt(char **map);

    int move_box_u(game_t *game, pl_t *pl);
    int move_box_d(game_t *game, pl_t *pl);
    int move_box_l(game_t *game, pl_t *pl);
    int move_box_r(game_t *game, pl_t *pl);

    int move_box_vert(game_t *game, pl_t *pl, int alpha);
    int move_box_hori(game_t *game, pl_t *pl, int alpha);
    int move_vert(game_t *game, pl_t *pl, int alpha);
    int move_hori(game_t *game, pl_t *pl, int alpha);

    int move_u(game_t *game, pl_t *pl);
    int move_d(game_t *game, pl_t *pl);
    int move_l(game_t *game, pl_t *pl);
    int move_r(game_t *game, pl_t *pl);

    int check_circle(game_t *game, pl_t *pl);
    void find_pl(game_t *game, pl_t *pl);
    game_t *find_hole(game_t *game);

    int win_condition(game_t *game);

#endif /* !SOKOBAN_H_ */
