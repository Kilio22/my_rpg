/*
** EPITECH PROJECT, 2018
** my_strdup
** File description:
** description
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *str)
{
    char *result = malloc(sizeof(char) * (my_strlen(str)+1));
    return (result);
}
