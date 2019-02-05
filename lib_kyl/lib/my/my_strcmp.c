/*
** EPITECH PROJECT, 2018
** task05
** File description:
** reproduce the behavior of the strcmp function
*/

#include "my.h"

int my_strcmp2(char *s1, char *s2)
{
    int len1 = 0;
    int len2 = 0;
    int result = 0;

    for (len1 = 0; s1[len1] == '.' || s1[len1] == '/'; len1++);
    for (len2 = 0; s2[len2] == '.' || s2[len2] == '/'; len2++);
    while (s1[len1] != '\0' && s2[len2] != '\0' && s1[len1] == s2[len2]) {
        len1++;
        len2++;
    }
    result = s1[len1] - s2[len2];
    free(s1);
    free(s2);
    return (result);
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
        i++;
    return (s1[i] - s2[i]);
}
