/*
** EPITECH PROJECT, 2023
** B-PSU-100-MAR-1-1-sokoban-amine.bechagra
** File description:
** fichier_str_ab
*/

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "../include/my.h"

char *fichier_str_ab(char *filename)
{
    int fd;
    char c;
    int q = 0;
    char *str = malloc(sizeof(char) * 10000);

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        exit(84);
    while (read(fd, &c, 1)) {
        str[q] = c;
        q++;
    }
    str[q] = '\0';
    close(fd);
    return str;
}
