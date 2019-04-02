/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** compare 2 strings
*/

#include "my_str.h"

my_bool_t my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i])
            return (FALSE);
        i++;
    }
    if (s1[i] != s2[i])
        return (FALSE);
    return (TRUE);
}

my_bool_t my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    int returned;
    int res;

    while (i < n - 1 && s1[i] == s2[i] && s2[i] && s1[i])
        i++;
    returned = (s1[i] - s2[i]);
    res = (returned == 0) ? TRUE : FALSE;
    return (res);
}
