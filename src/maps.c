/*
** EPITECH PROJECT, 2022
** EPITECH [WSL : Ubuntu]
** File description:
** maps
*/

#include "sokoban.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>

int get_rows(char *str)
{
    int rows = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == '\n') {
            rows += 1;
        }
        i += 1;
    }

    return rows;
}

char *get_map(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);

    if (fd == -1)
        return NULL;

    char *buffer = NULL;
    struct stat go_map;
    stat(filepath, &go_map);
    buffer = malloc(go_map.st_size + 1);
    read(fd, buffer, go_map.st_size);
    buffer[go_map.st_size] = '\0';

    return buffer;
}

void alloc_map(char **map, char *str)
{
    int count_words = 0;
    int k = 0;

    for (int i = 0; str[i] != '\0'; i += 1) {
        count_words += 1;
        if (str[i] == '\n') {
            map[k] = malloc(sizeof(char) * (count_words + 1));
            map[k][count_words] = '\0';
            count_words = 0;
            k += 1;
        }
    }
}

void init_map(char **map, char *str)
{
    int j = 0;
    int k = 0;

    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == '\n') {
            k += 1;
            j = 0;
        }
        if (str[i] != '\n') {
            map[k][j] = str[i];
            j += 1;
        }
    }
}
