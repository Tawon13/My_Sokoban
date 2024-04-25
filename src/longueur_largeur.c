/*
** EPITECH PROJECT, 2023
** B-PSU-100-MAR-1-1-sokoban-amine.bechagra
** File description:
** array
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include "../include/my.h"

int widht(char *str)
{
    int q = 1;

    while (str[q] != '\n')
        q++;
    return q - 1;
}

int height(char *str)
{
    int q = 1;
    int height = 0;

    while (str[q] != '\0') {
        if (str[q] == '\n')
            height++;
        q++;
    }
    return height;
}
