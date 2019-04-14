/*
** EPITECH PROJECT, 2018
** mg_strcat
** File description:
** concatenate 2 str
*/

#include "mg_str.h"

char *mg_strcat(char **s1, char const *s2)
{
    int size = mg_strlen(*s1) + mg_strlen(s2) + 1;
    char *new_str = malloc(sizeof(char) * size);

    mg_strcpy(new_str, *s1);
    mg_strcpy(new_str + mg_strlen(*s1), s2);
    free(*s1);
    *s1 = new_str;
    return (new_str);
}

char *mg_strncat(char **s1, char const *s2, int n)
{
    int size = (mg_strlen(s2) < n) ? mg_strlen(s2) : n;
    char *new_str;

    size += mg_strlen(*s1);
    new_str = malloc(sizeof(char) * (size + 1));
    mg_strcpy(new_str, *s1);
    mg_strncpy(new_str + mg_strlen(*s1), s2, n);
    free(*s1);
    *s1 = new_str;
    return new_str;
}
