/*
** EPITECH PROJECT, 2018
** mg_strreplace
** File description:
** mg_strreplace
*/

#include "mg_str.h"

static int first_str_occurence(char *str, char const *to_find)
{
    int size = mg_strlen(to_find);
    char *substring = str;
    int repeat = mg_strlen(str) - mg_strlen(to_find);
    for (int i = 0; i < repeat + 1; i++){
        if (mg_strncmp(substring, to_find, size) == 1)
            return i;
        substring++;
    }
    return -1;
}

char *mg_strreplace(char **str, char const *to_find, char const *substitute)
{
    int size = mg_strlen(*str) + mg_strlen(substitute) - mg_strlen(to_find);
    char *new_str = malloc(sizeof(char) * (size + 1));
    int offset = first_str_occurence(*str, to_find);
    if (offset == -1)
        return *str;
    mg_strncpy(new_str, *str, offset);
    mg_strcpy(new_str + offset, substitute);
    char *tmp = *str + offset + mg_strlen(to_find);
    mg_strcpy(new_str + offset + mg_strlen(substitute), tmp);
    free(*str);
    *str = new_str;
    return new_str;
}
