/*
** EPITECH PROJECT, 2018
** binary
** File description:
** convert unsigned numbers into binary
*/

#include "my.h"

int put_binary(unsigned int nb)
{
    unsigned int i = 0;
    char binary[] = "01";
    char *result;

    result = malloc(sizeof(char) * nb / 2 + 1);
    result[nb / 2 + 1] = '\0';
    while (nb > 0) {
        result[i] = binary[nb % 2];
        nb = nb / 2;
        i++;
    }
    my_revstr(result);
    return (my_putstr(result));
}
