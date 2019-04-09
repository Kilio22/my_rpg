/*
** EPITECH PROJECT, 2018
** my_revstr
** File description:
** reverse an string
*/

#include "my_str.h"

char *my_revstr(char *str)
{
    int size = my_strlen(str);
    char *dest = my_strdup(str);
    int i = size - 1;
    int j = 0;

    if (!dest)
        return (NULL);
    while (dest[j] != '\0'){
        str[j] = dest[i];
        j++;
        i--;
    }
    str[j] = '\0';
    free(dest);
    return (str);
}
