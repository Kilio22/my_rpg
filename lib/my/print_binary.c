/*
** EPITECH PROJECT, 2018
** printf binary
** File description:
** print binary
*/

#include "my.h"
#include "printf.h"

int print_binary(va_list list)
{
    return (put_binary(va_arg(list, unsigned int)));
}
