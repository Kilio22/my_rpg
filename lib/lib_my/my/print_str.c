/*
** EPITECH PROJECT, 2018
** print str
** File description:
** str
*/

#include "my.h"
#include "printf.h"

int print_str(va_list list)
{
    return (my_putstr(va_arg(list, char *)));
}
