/*
** EPITECH PROJECT, 2023
** B-CPE-110-MAR-1-1-settingup-amine.bechagra
** File description:
** array
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include "my.h"


char **string_word_array_ab(int hauteur, int largeur, char *filename)
{
    int i = 0;
    int j = 0;
    int z = 0;
    char **map;

    map = malloc(sizeof(char *) * hauteur);
    while (i < hauteur) {
        map[i] = (char *)malloc(sizeof(char) * (largeur + 1));
        map[i][largeur] = '\0';
        i++;
    }
    for (i = 0; i < hauteur; i++) {
        for (j = 0; j <= largeur; j++) {
            map[i][j] = filename[z];
            z++;
        }
    }
    return map;
}
