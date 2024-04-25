/*
** EPITECH PROJECT, 2023
** B-PSU-100-MAR-1-1-sokoban-amine.bechagra
** File description:
** string_word_array_ab
*/

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "../include/my.h"

char **string_word_array_ab(int height, char *file)
{
    int a = 0;
    int z = 0;
    int line_width;
    char **map;

    map = malloc(sizeof(char *) * (height + 1));
    for (int i = 0; i < height; i++) {
        line_width = get_line_width(file, z);
        map[i] = (char *)malloc(sizeof(char) * (line_width + 1));
        map[i][line_width] = '\0';
        for (a = 0; a < line_width; a++) {
            map[i][a] = file[z];
            z++;
        }
        if (file[z] == '\n')
            z++;
    }
    map[height] = NULL;
    printf("%d\n", line_width);
    return map;
}
