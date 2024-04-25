/*
** EPITECH PROJECT, 2023
** B-PSU-100-MAR-1-1-sokoban-amine.bechagra
** File description:
** my_sokoban
*/

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "../include/my.h"

int counto(char **map)
{
    int x = 0;
    int nbO = 0;
    int y = 0;

    while (map[x] != NULL) {
        while (map[x][y] != '\0') {
            nbO = nbO + (map[x][y] == 'O');
            y++;
        }
        y = 0;
        x++;
    }
    return nbO;
}

void display_map(char **map, int height)
{
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    for (int i = 0; i < height; i++) {
        mvprintw(i, 0, "%s", map[i]);
    }
    refresh();
}

static void update_map(char **map, int row, int col)
{
    if (map[row][col] == ' ') {
        map[row][col] = 'O';
    }
}

static void process_positions(char **map, int **posO, int nbO)
{
    for (int i = 0; i < nbO; i++) {
        update_map(map, posO[i][0], posO[i][1]);
    }
}

void main2(char **map, int keys, int x, int **posO)
{
    int nbO = counto(map);

    while (keys != ' ') {
        player_move(map, keys);
        process_positions(map, posO, nbO);
        display_map(map, x);
        keys = getch();
    }
    for (int q = 0; q < x; q++)
        free(map[q]);
}

int stocko2(char **map, int **posO)
{
    int i = 0;
    int x = 0;
    int b = 0;
    int y = 0;

    while (map[x] != NULL) {
        while (map[x][y] != '\0') {
            if (map[x][y] == 'O') {
                posO[b][0] = x;
                posO[b][1] = y;
                b++;
            }
            y++;
        }
        y = 0;
        x++;
    }
    return 0;
}

static int **stocko(char **map)
{
    int nbO = counto(map);
    int **posO;
    int i = 0;
    int x = 0;
    int b = 0;
    int y = 0;

    posO = malloc(sizeof(int *) * nbO);
    while (i != nbO) {
        posO[i] = malloc(sizeof(int) * 2);
        i++;
    }
    stocko2(map, posO);
    return posO;
}

int main(int argc, char **argv)
{
    int keys;
    char *str;
    int x;
    char **map;
    int **posO;

    if (argc < 2)
        return 84;
    if (argv[1][0] == '-' && argv[1][1] == 'h') {
        my_putstr("Sokoban est un jeu de casse-tete");
        return 0;
    }
    str = fichier_str_ab(argv[1]);
    x = height(str);
    map = string_word_array_ab(x, str);
    posO = stocko(map);
    keys = getch();
    main2(map, keys, x, posO);
    endwin();
    return 0;
}
