/*
** EPITECH PROJECT, 2018
** my_strdup
** File description:
** my_strdup
*/

#include "my_str.h"

char *my_strdup(char const *src)
{
    char *new_str = malloc(sizeof(char) * (my_strlen(src) + 1));

    if (!new_str)
        return (NULL);
    my_strcpy(new_str, src);
    new_str[my_strlen(src)] = '\0';
    return (new_str);
}

char *my_strndup(char const *src, int n)
{
    int size = (my_strlen(src) < n) ? my_strlen(src) : n;
    char *new_str = malloc(sizeof(char) * (size + 1));

    if (!new_str)
        return (NULL);
    my_strncpy(new_str, src, n);
    return (new_str);
}