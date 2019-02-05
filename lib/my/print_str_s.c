/*
** EPITECH PROJECT, 2018
** printf str S
** File description:
** str S
*/

#include "my.h"
#include "printf.h"

int print_str_s(va_list list)
{
    return (my_putstr_s(va_arg(list, char *)));
}
