/*
** EPITECH PROJECT, 2023
** B-PSU-100-MAR-1-1-sokoban-amine.bechagra
** File description:
** mouvement
*/

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "../include/my.h"

int movement(char **map, int *player_i, int *player_j, int i)
{
    for (int j = 0; map[i][j] != '\0'; j++) {
        if (map[i][j] == 'P') {
            *player_i = i;
            *player_j = j;
        }
    }
    return 0;
}

static int mouvement_o(char **map, int *player_i, int *player_j, int i)
{
    int player_i1;
    int player_i2;

    for (int j = 0; map[i][j] != '\0'; j++) {
        if (map[i][j] == 'O') {
            *player_i = player_i2;
            *player_j = player_i2;
        }
    }
    return 0;
}

void find_player(char **map, int *player_i, int *player_j)
{
    *player_i = -1;
    *player_j = -1;
    for (int i = 0; map[i] != NULL; i++) {
        movement(map, player_i, player_j, i);
    }
}

static int haut(char **map, int player_i, int player_j)
{
    if (player_i > 0 && map[player_i - 1][player_j] == ' ') {
        map[player_i - 1][player_j] = 'P';
        map[player_i][player_j] = ' ';
    }
    if (map[player_i - 1][player_j] == 'X') {
        if (map[player_i - 2][player_j] == 'O') {
            hauto(map, player_i, player_j);
        }
    }
    if (map[player_i - 1][player_j] == 'X') {
        if (map[player_i - 2][player_j] == ' ') {
            map[player_i][player_j] = ' ';
            map[player_i - 1][player_j] = 'P';
            map[player_i - 2][player_j] = 'X';
        }
    }
    return 0;
}

static int down(char **map, int player_i, int player_j)
{
    if (map[player_i + 1] != NULL && map[player_i + 1][player_j] == ' ') {
        map[player_i + 1][player_j] = 'P';
        map[player_i][player_j] = ' ';
    }
    if (map[player_i + 1][player_j] == 'X') {
        if (map[player_i + 2][player_j] == 'O') {
            downo(map, player_i, player_j);
        }
    }
    if (map[player_i + 1][player_j] == 'X') {
        if (map[player_i + 2][player_j] == ' ') {
            map[player_i][player_j] = ' ';
            map[player_i + 1][player_j] = 'P';
            map[player_i + 2][player_j] = 'X';
        }
    }
    return 0;
}

static int left(char **map, int player_i, int player_j)
{
    if (player_j > 0 && map[player_i][player_j - 1] == ' ') {
        map[player_i][player_j - 1] = 'P';
        map[player_i][player_j] = ' ';
    }
    if (map[player_i][player_j - 1] == 'X') {
        if (map[player_i][player_j - 2] == 'O') {
            lefto(map, player_i, player_j);
        }
    }
    if (map[player_i][player_j - 1] == 'X') {
        if (map[player_i][player_j - 2] == ' ') {
            map[player_i][player_j] = ' ';
            map[player_i][player_j - 1] = 'P';
            map[player_i][player_j - 2] = 'X';
        }
    }
    return 0;
}

static int right(char **map, int player_i, int player_j)
{
    if (player_j > 0 && map[player_i][player_j + 1] == ' ') {
        map[player_i][player_j + 1] = 'P';
        map[player_i][player_j] = ' ';
    }
    if (map[player_i][player_j + 1] == 'X') {
        if (map[player_i][player_j + 2] == 'O') {
            righto(map, player_i, player_j);
        }
    }
    if (map[player_i][player_j + 1] == 'X') {
        if (map[player_i][player_j + 2] == ' ') {
            map[player_i][player_j] = ' ';
            map[player_i][player_j + 1] = 'P';
            map[player_i][player_j + 2] = 'X';
        }
    }
    return 0;
}

void move_player(char **map, int player_i, int player_j, int direction)
{
    switch (direction) {
        case KEY_UP:
            haut(map, player_i, player_j);
            break;
        case KEY_DOWN:
            down(map, player_i, player_j);
            break;
        case KEY_LEFT:
            left(map, player_i, player_j);
            break;
        case KEY_RIGHT:
            right(map, player_i, player_j);
            break;
    }
}

void player_move(char **map, int direction)
{
    int player_i;
    int player_j;

    find_player(map, &player_i, &player_j);
    move_player(map, player_i, player_j, direction);
}
