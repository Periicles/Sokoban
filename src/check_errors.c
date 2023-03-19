/*
** EPITECH PROJECT, 2023
** errors
** File description:
** errors
*/

#include "sokoban.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

static int correct_args(int ac)
{
    if (ac != 2)
        return EPITECH_ERROR;

    return 0;
}

static int file_exists(char *filepath)
{
    int fd = open(filepath, O_RDONLY);

    if (fd == -1) {
        close(fd);
        return EPITECH_ERROR;
    } else {
        return 0;
    }
    close(fd);
}

static int empty_file(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *str = malloc(sizeof(char) * 33);

    if (read(fd, str, 31) <= 0) {
        close(fd);
        return EPITECH_ERROR;
    }
    close(fd);

    return 0;
}

int check_errors(int ac, char **av)
{
    if (correct_args(ac) == 84)
        return EPITECH_ERROR;
    if (ac == 2 && (av[1][0] == '-' && av[1][1] == 'h'))
        help();
    if (file_exists(av[1]) == 84)
        return EPITECH_ERROR;
    if (empty_file(av[1]) == 84)
        return EPITECH_ERROR;

    return 0;
}
