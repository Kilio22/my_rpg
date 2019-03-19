/*
** EPITECH PROJECT, 2019
** 1MAKEFILE
** File description:
** my_realloc
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

char *my_realloc(char *input_str, int nb)
{
    char *save_str = malloc(sizeof(char) * nb);
    int lenght = my_strlen(input_str);

    for (int i = 0; i < lenght; i++)
        save_str[i] = input_str[i];
    free(input_str);
    return (save_str);
}