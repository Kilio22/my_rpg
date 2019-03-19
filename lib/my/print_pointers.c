/*
** EPITECH PROJECT, 2018
** print pointers
** File description:
** pointers
*/

#include "my.h"
#include "printf.h"

int print_pointers(va_list list)
{
    return (put_pointers(va_arg(list, long)));
}
