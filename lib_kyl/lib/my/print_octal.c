/*
** EPITECH PROJECT, 2018
** print octal
** File description:
** octal
*/

#include "my.h"
#include "printf.h"

int print_octal(va_list list)
{
    return (put_octal(va_arg(list, int)));
}
