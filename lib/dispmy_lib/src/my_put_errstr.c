/*
** EPITECH PROJECT, 2018
** mg_put_errstr
** File description:
** put an str on the standard err output
*/

#include <stdio.h>
#include "my_display.h"

static int s_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

void mg_put_errstr(char const *str)
{
    fwrite(str, sizeof(char), s_strlen(str), stderr);
}
