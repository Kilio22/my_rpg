/*
** EPITECH PROJECT, 2018
** my_put_errstr
** File description:
** put an str on the standard err output
*/
#include "my_display.h"

static int s_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

void my_put_errstr(char const *str)
{
    write(2, str, s_strlen(str));
}
