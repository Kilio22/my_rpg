/*
** EPITECH PROJECT, 2018
** mg_putchar
** File description:
** display an char
*/

#include "my_display.h"

void mg_putchar(char c)
{
    write(1, &c, 1);
}
