/*
** EPITECH PROJECT, 2018
** str dup pimp
** File description:
** ptdr
*/

#include <stdlib.h>

char *my_strxdup(char const *src, int n)
{
    char *dest = malloc(n + 1);
    int i = 0;

    while (src[i] != '\0' && i < n) {
        dest[i] = src[i];
        i++;
    }
    dest[n] = '\0';
    return (dest);
}