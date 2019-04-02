/*
** EPITECH PROJECT, 2018
** my_strcpy
** File description:
** copy an string into another
*/

#include "my_str.h"

char *my_strcpy(char *dest, char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        dest[i] = str[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

char *my_strncpy(char *dest, char const *src, int n)
{
    int size = (my_strlen(src) > n) ? n : my_strlen(src);

    for (int i = 0; i < size; i++) {
        dest[i] = src[i];
    }
    dest[size] = '\0';
    return (dest);
}