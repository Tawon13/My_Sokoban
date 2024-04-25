/*
** EPITECH PROJECT, 2023
** B-PSU-100-MAR-1-1-sokoban-amine.bechagra
** File description:
** mouvemento
*/

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "../include/my.h"

int hauto(char **map, int player_i, int player_j)
{
    if (map[player_i - 3][player_j] == ' '
    || map[player_i - 3][player_j] == '#') {
        map[player_i][player_j] = ' ';
        map[player_i - 1][player_j] = 'P';
        map[player_i - 2][player_j] = 'X';
    }
    return 0;
}

int downo(char **map, int player_i, int player_j)
{
    if (map[player_i + 3][player_j] == ' '
    || map[player_i + 3][player_j] == '#') {
        map[player_i][player_j] = ' ';
        map[player_i + 1][player_j] = 'P';
        map[player_i + 2][player_j] = 'X';
    }
    return 0;
}

int lefto(char **map, int player_i, int player_j)
{
    if (map[player_i][player_j - 3] == ' '
    || map[player_i][player_j - 3] == '#') {
        map[player_i][player_j] = ' ';
        map[player_i][player_j - 1] = 'P';
        map[player_i][player_j - 2] = 'X';
    }
    return 0;
}

int righto(char **map, int player_i, int player_j)
{
    if (map[player_i][player_j + 3] == ' '
    || map[player_i][player_j + 3] == '#') {
        map[player_i][player_j] = ' ';
        map[player_i][player_j + 1] = 'P';
        map[player_i][player_j + 2] = 'X';
    }
    return 0;
}
