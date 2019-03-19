/*
** EPITECH PROJECT, 2018
** octal
** File description:
** conversion in octal
*/

#include "my.h"

int put_octal_d(int nb)
{
    int i = 0;
    char octal[] = "01234567";
    char result[4];

    for (int j = 0; j != 3; j++)
        result[j] = '0';
    while (nb > 0) {
        result[i] = octal[nb % 8];
        nb = nb / 8;
        i++;
    }
    my_revstr(result);
    result[4] = '\0';
    return (my_putstr(result));
}
