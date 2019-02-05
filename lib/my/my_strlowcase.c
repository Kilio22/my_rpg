/*
** EPITECH PROJECT, 2018
** task08
** File description:
** lowercase
*/

#include <unistd.h>
#include "my.h"

char *my_strlowcase(char *str)
{
    int i = 0;
    char *new = my_strdup(str);

    while (new[i] != '\0') {
        if (new[i] >= 'A' && new[i] <= 'Z') {
            new[i] = new[i] + 32;
        }
        i++;
    }
    return (new);
}