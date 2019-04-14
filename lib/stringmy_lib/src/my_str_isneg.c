/*
** EPITECH PROJECT, 2018
** mg_str_isneg
** File description:
** know if an str is neg or not (mathematic sense)
*/
#include "mg_str.h"

int mg_str_isneg(char const *str)
{
    if (mg_str_isnum(str) == 0)
        return -1;
    if (str[0] == '-')
        return 1;
    return 0;
}
