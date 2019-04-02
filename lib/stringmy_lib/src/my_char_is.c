/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** my_char_is
*/

#include "my_str.h"

my_bool_t my_char_isletter(char c)
{
    if (my_char_isuppercase(c) == 1 || my_char_islowercase(c) == 1)
        return (TRUE);
    return (FALSE);
}

my_bool_t my_char_islowercase(char c)
{
    if (c >= 'a' && c <= 'z')
        return (TRUE);
    return (FALSE);
}

my_bool_t my_char_isnumber(char c)
{
    if (c >= '0' && c <= '9')
        return (TRUE);
    return (FALSE);
}

my_bool_t my_char_isuppercase(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (TRUE);
    return (FALSE);
}
