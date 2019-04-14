/*
** EPITECH PROJECT, 2018
** mg_str_isnum
** File description:
** define is an str contain exclusively digits
*/

#include "mg_str.h"

mg_bool_t mg_str_isnum(char const *str)
{
    int i = 0;
    int negative = 0;
    mg_bool_t is_float = FALSE;
    if (str[0] == '-'){
        i++;
        negative = 1;
    }
    while (str[i] != '\0'){
        if (str[i] == '.' && is_float == FALSE){
            is_float = TRUE;
            i++;
        }
        if (mg_char_isnumber(str[i]) == 0)
            return FALSE;
        i++;
    }
    if (i >= negative + 1)
        return TRUE;
    return FALSE;
}

mg_bool_t mg_str_isint(char const *str)
{
    int i = 0;
    int negative = 0;
    if (str[0] == '-'){
        i++;
        negative = 1;
    }
    while (str[i] != '\0'){
        if (mg_char_isnumber(str[i]) == 0)
            return FALSE;
        i++;
    }
    if (i >= negative + 1)
        return TRUE;
    return FALSE;
}