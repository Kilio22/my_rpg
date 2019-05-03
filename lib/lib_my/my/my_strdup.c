/*
** EPITECH PROJECT, 2018
** task01
** File description:
** allocate memory
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    int i = 0;
    int f =  my_strlen(src);
    char *dest;

    if (src == NULL)
        return (NULL);
    dest = malloc(sizeof(char) * (f + 1));
    if (!dest)
        return NULL;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
