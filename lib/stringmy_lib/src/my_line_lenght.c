/*
** EPITECH PROJECT, 2018
** my_line_lenght
** File description:
** my_line_lenght
*/

#include "my_str.h"

int my_line_lenght(char const *str)
{
    int i = 0;

    while (str[i] != '\0' && str[i] != '\n')
        i++;
    return (i);
}