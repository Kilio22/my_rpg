/*
** EPITECH PROJECT, 2018
** my_revstr
** File description:
** reverse a string
*/
#include "my.h"

char *my_revstr(char *str)
{
    int i = my_strlen(str) - 1;
    int a = 0;
    char b;

    while (a < i) {
        b = str[a];
        str[a] = str[i];
        str[i] = b;
        a++;
        i--;
    }
    return (str);
}