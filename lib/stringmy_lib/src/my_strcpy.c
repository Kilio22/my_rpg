/*
** EPITECH PROJECT, 2018
** mg_strcpy
** File description:
** copy an string into another
*/

#include "mg_str.h"

char *mg_strcpy(char *dest, char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        dest[i] = str[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

char *mg_strncpy(char *dest, char const *src, int n)
{
    int size = (mg_strlen(src) > n) ? n : mg_strlen(src);

    for (int i = 0; i < size; i++) {
        dest[i] = src[i];
    }
    dest[size] = '\0';
    return (dest);
}