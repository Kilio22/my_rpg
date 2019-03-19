/*
** EPITECH PROJECT, 2018
** printf bnr
** File description:
** put nbr
*/

#include "my.h"
#include "printf.h"

int print_nbr(va_list list)
{
    return (my_put_nbr(va_arg(list, int)));
}
