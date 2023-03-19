/*
** EPITECH PROJECT, 2022
** EPITECH [WSL : Ubuntu]
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    #include <curses.h>

typedef struct pl_s {
    int x;
    int y;
}pl_t;

typedef struct game_s {
    int nb_holes;
    int nb_crates;
    WINDOW *win;
    int nb_rows;
    char **map;
    char **cpy;
    int key;
}game_t;

#endif /* !STRUCT_H_ */
