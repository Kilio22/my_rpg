/*
** EPITECH PROJECT, 2018
** mg_revstr
** File description:
** reverse an string
*/

#include "mg_str.h"

char *mg_revstr(char *str)
{
    int size = mg_strlen(str);
    char *dest = mg_strdup(str);
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
