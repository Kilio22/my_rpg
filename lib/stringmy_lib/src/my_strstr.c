/*
** EPITECH PROJECT, 2018
** mg_strstr
** File description:
** mg_strstr
*/

#include "mg_str.h"

char *mg_strstr(char *str, char const *to_find)
{
    int size = mg_strlen(to_find);
    char *substring = str;
    int repeat = mg_strlen(str) - mg_strlen(to_find);

    for (int i = 0; i < repeat + 1; i++){
        if (mg_strncmp(substring, to_find, size) == 1)
            return (substring);
        substring++;
    }
    substring = "\0";
    return (substring);
}
