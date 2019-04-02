/*
** EPITECH PROJECT, 2018
** my_str_isneg
** File description:
** know if an str is neg or not (mathematic sense)
*/
#include "my_str.h"

int my_str_isneg(char const *str)
{
    if (my_str_isnum(str) == 0)
        return -1;
    if (str[0] == '-')
        return 1;
    return 0;
}
