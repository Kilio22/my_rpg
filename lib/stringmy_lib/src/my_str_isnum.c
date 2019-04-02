/*
** EPITECH PROJECT, 2018
** my_str_isnum
** File description:
** define is an str contain exclusively digits
*/

#include "my_str.h"

my_bool_t my_str_isnum(char const *str)
{
    int i = 0;
    int negative = 0;
    my_bool_t is_float = FALSE;
    if (str[0] == '-'){
        i++;
        negative = 1;
    }
    while (str[i] != '\0'){
        if (str[i] == '.' && is_float == FALSE){
            is_float = TRUE;
            i++;
        }
        if (my_char_isnumber(str[i]) == 0)
            return FALSE;
        i++;
    }
    if (i >= negative + 1)
        return TRUE;
    return FALSE;
}

my_bool_t my_str_isint(char const *str)
{
    int i = 0;
    int negative = 0;
    if (str[0] == '-'){
        i++;
        negative = 1;
    }
    while (str[i] != '\0'){
        if (my_char_isnumber(str[i]) == 0)
            return FALSE;
        i++;
    }
    if (i >= negative + 1)
        return TRUE;
    return FALSE;
}