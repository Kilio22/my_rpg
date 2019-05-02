/*
** EPITECH PROJECT, 2018
** my_putchar
** File description:
** display a char
*/

#include <stdio.h>

int my_putchar(char c)
{
    fwrite(&c, sizeof(char), 1, stdout);
    return 1;
}
