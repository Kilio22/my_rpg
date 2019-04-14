/*
** EPITECH PROJECT, 2018
** mg_strlen
** File description:
** compute the lenght of an str
*/
#include "mg_str.h"

int mg_strlen(char const *str)
{
    register int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}
