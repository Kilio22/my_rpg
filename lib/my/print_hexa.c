/*
** EPITECH PROJECT, 2018
** print hex
** File description:
** hexa
*/

#include "my.h"
#include "printf.h"

int print_hexa(va_list list)
{
    return (put_hexa(va_arg(list, int)));
}
