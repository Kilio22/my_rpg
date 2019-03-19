/*
** EPITECH PROJECT, 2018
** put pointers
** File description:
** pointers
*/

#include "my.h"

int put_pointers(long nb)
{
    int i = 0;
    char pointers[] = "0123456789abcdef";
    char result[13];
    int nbchar = 2;

    result[13] = '\0';
    while (nb > 0) {
        result[i] = pointers[nb % 16];
        nb = nb / 16;
        i++;
    }
    my_revstr(result);
    my_putstr("0x");
    nbchar += my_putstr(result);
    return (nbchar);
}
