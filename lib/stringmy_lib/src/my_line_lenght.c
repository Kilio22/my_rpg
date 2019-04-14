/*
** EPITECH PROJECT, 2018
** mg_line_lenght
** File description:
** mg_line_lenght
*/

#include "mg_str.h"

int mg_line_lenght(char const *str)
{
    int i = 0;

    while (str[i] != '\0' && str[i] != '\n')
        i++;
    return (i);
}