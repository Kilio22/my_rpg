/*
** EPITECH PROJECT, 2018
** my_strstr
** File description:
** my_strstr
*/

#include "my_str.h"

char *my_strstr(char *str, char const *to_find)
{
    int size = my_strlen(to_find);
    char *substring = str;
    int repeat = my_strlen(str) - my_strlen(to_find);

    for (int i = 0; i < repeat + 1; i++){
        if (my_strncmp(substring, to_find, size) == 1)
            return (substring);
        substring++;
    }
    substring = "\0";
    return (substring);
}
