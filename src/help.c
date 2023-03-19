/*
** EPITECH PROJECT, 2022
** EPITECH [WSL : Ubuntu]
** File description:
** help
*/

#include "my.h"
#include "sokoban.h"

int help(void)
{
    my_putstr("USAGE\n");
    my_putstr("\t./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("\tmap file representing the wharehouse map, containing ");
    my_putstr("'#' for walls,\n");
    my_putstr("\t'P' for the player, 'X' for boxes and 'O' for ");
    my_putstr("storage locations.\n");

    return 0;
}
