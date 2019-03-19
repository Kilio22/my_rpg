/*
** EPITECH PROJECT, 2018
** octal
** File description:
** conversion in octal
*/

#include "my.h"

int put_octal(int nb)
{
    int i = 0;
    char octal[] = "01234567";
    char *result;

    result = malloc(sizeof(char) * nb / 8 + 1);
    result[nb / 8 + 1] = '\0';
    while (nb > 0) {
        result[i] = octal[nb % 8];
        nb = nb / 8;
        i++;
    }
    my_revstr(result);
    return (my_putstr(result));
}