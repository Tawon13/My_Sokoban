/*
** EPITECH PROJECT, 2024
** B-PSU-100-MAR-1-1-sokoban-amine.bechagra
** File description:
** my_putstr
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "../include/my.h"

int my_putstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
    return 0;
}
