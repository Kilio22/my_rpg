/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2018
** File description:
** my_int_to_char
*/

#include "my.h"

char *my_int_to_char(int nb)
{
    int i = 1;
    int nbchar = 0;
    int char_pos = 0;
    char *new = malloc(sizeof(char) * (my_intlen(nb) + 2));

    if (nb <= 0) {
        new[0] = '0';
        new[1] = '\0';
        return (new);
    }
    while (nb / i > 0)
        i = i * 10;
    i = i / 10;
    for (; i > 0; nbchar++) {
        new[char_pos] = nb / i % 10 + '0';
        char_pos++;
        i = i / 10;
    }
    new[char_pos] = '\0';
    return (new);
}