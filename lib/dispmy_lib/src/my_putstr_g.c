/*
** EPITECH PROJECT, 2018
** mg_putstr
** File description:
** function for display an entire str
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

void mg_putstr(char const *str)
{
    fwrite(str, sizeof(char), s_strlen(str), stdout);
}
