/*
** EPITECH PROJECT, 2018
** mg_putchar
** File description:
** display an char
*/

#include <stdio.h>
#include "my_display.h"

void mg_putchar(char c)
{
    fwrite(&c, sizeof(char), 1, stdout);
}
