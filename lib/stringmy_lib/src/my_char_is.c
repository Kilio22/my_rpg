/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** mg_char_is
*/

#include "mg_str.h"

mg_bool_t mg_char_isletter(char c)
{
    if (mg_char_isuppercase(c) == 1 || mg_char_islowercase(c) == 1)
        return (TRUE);
    return (FALSE);
}

mg_bool_t mg_char_islowercase(char c)
{
    if (c >= 'a' && c <= 'z')
        return (TRUE);
    return (FALSE);
}

mg_bool_t mg_char_isnumber(char c)
{
    if (c >= '0' && c <= '9')
        return (TRUE);
    return (FALSE);
}

mg_bool_t mg_char_isuppercase(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (TRUE);
    return (FALSE);
}
