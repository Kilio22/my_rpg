/*
** EPITECH PROJECT, 2018
** printf char
** File description:
** char
*/

#include "my.h"
#include "printf.h"

int print_char(va_list list)
{
    my_putchar(va_arg(list, int));
    return (1);
}
