/*
** EPITECH PROJECT, 2018
** my_itoa
** File description:
** int into char
*/

#include "my.h"

char *my_itoa(int nb, char *result)
{
    int i = 0;
    int buff;
    while (nb != 0) {
        buff = nb % 10;
        result[i] = (buff > 9)? (buff - 10) + 'a' : buff + '0';
        i++;
        nb /= 10;
    }
    result = my_revstr(result);
    return (result);
}