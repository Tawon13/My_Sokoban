/*
** EPITECH PROJECT, 2023
** B-PSU-100-MAR-1-1-sokoban-amine.bechagra
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

    #include <stdio.h>
    #include <fcntl.h>
    #include <unistd.h>

char **string_word_array_ab(int height, char *file);
char *fichier_str_ab(char *filename);
int height(char *str);
int widht(char *str);
int get_line_width(char *str, int start);
char **string_word_array_ab(int height, char *file);
void find_player(char **map, int *player_i, int *player_j);
int movement(char **map, int *player_i1, int *player_j1, int i);
int move_player2(char **map, int player_i, int player_j);
int move_player3(char **map, int player_i, int player_j);
void move_player(char **map, int player_i, int player_j, int direction);
void player_move(char **map, int mouv);
int my_putstr(char *str);
void my_putchar(char c);
int hauto(char **map, int player_i, int player_j);
int downo(char **map, int player_i, int player_j);
int lefto(char **map, int player_i, int player_j);
int righto(char **map, int player_i, int player_j);

#endif
