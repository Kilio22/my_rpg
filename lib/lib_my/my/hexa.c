/*
** EPITECH PROJECT, 2018
** conversion in hexa
** File description:
** hexa conv
*/

#include "my.h"

int put_hexa(int nb)
{
    int i = 0;
    char hexa[] = "0123456789abcdef";
    char *result;

    result = malloc(sizeof(char) * nb / 16 + 1);
    result[nb / 16 + 1] = '\0';
    while (nb > 0) {
        result[i] = hexa[nb % 16];
        nb = nb / 16;
        i++;
    }
    my_revstr(result);
    return (my_putstr(result));
}
