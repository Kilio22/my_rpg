/*
** EPITECH PROJECT, 2018
** my_strreplace
** File description:
** my_strreplace
*/

#include "my_str.h"

static int first_str_occurence(char *str, char const *to_find)
{
    int size = my_strlen(to_find);
    char *substring = str;
    int repeat = my_strlen(str) - my_strlen(to_find);
    for (int i = 0; i < repeat + 1; i++){
        if (my_strncmp(substring, to_find, size) == 1)
            return i;
        substring++;
    }
    return -1;
}

char *my_strreplace(char **str, char const *to_find, char const *substitute)
{
    int size = my_strlen(*str) + my_strlen(substitute) - my_strlen(to_find);
    char *new_str = malloc(sizeof(char) * (size + 1));
    int offset = first_str_occurence(*str, to_find);
    if (offset == -1)
        return *str;
    my_strncpy(new_str, *str, offset);
    my_strcpy(new_str + offset, substitute);
    char *tmp = *str + offset + my_strlen(to_find);
    my_strcpy(new_str + offset + my_strlen(substitute), tmp);
    free(*str);
    *str = new_str;
    return new_str;
}
