/*
** EPITECH PROJECT, 2018
** my_itoa
** File description:
** int into char
*/

#include <stdlib.h>
#include "../../../include/my.h"

char const BASE_DECIMAL[11] = "0123456789";

static int count_char(int nb)
{
    int i = 1;
    while (nb > 9) {
        i++;
        nb = nb / 10;
    }
    return (i);
}

static char *end_of_string(char *str, int count, int pos)
{
    str[count] = BASE_DECIMAL[pos];
    count++;
    str[count] = '\0';
    return (str);
}

char *my_itoa(int nb, char *str)
{
    char *score;
    char *text;
    int count = 0;
    int pos;

    score = malloc(sizeof(char) * (count_char(nb) + 2));
    for (; nb > 9; count++) {
        pos = nb % 10;
        score[count] = BASE_DECIMAL[pos];
        nb = nb / 10;
    }
    pos = nb % 10;
    score = end_of_string(score, count, pos);
    score = my_revstr(score);
    text = my_strncat(str, score, -1);
    free(score);
    return (text);
}