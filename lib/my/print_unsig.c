/*
** EPITECH PROJECT, 2018
** print unsig
** File description:
** unsig
*/

#include "my.h"
#include "printf.h"

int print_unsig(va_list list)
{
    return (put_unsign(va_arg(list, unsigned int)));
}
