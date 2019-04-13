/*
** EPITECH PROJECT, 2018
** array of functions
** File description:
** tab
*/

#include <stdarg.h>
#include "my.h"
#include "printf.h"

int check(char c)
{
    char verif[11] = "csSdiuoxXbp";
    int i = 0;

    while (verif[i] != '\0') {
        if (verif[i] == c)
            return i;
        i++;
    }
    return -1;
}

int printer(char c, va_list list)
{
    int nb = check(c);
    int counter = 0;
    int (*tab[11])(va_list list) = {&print_char, &print_str, &print_str_s,
&print_nbr, &print_nbr, &print_unsig, &print_octal, &print_hexa, &print_hexa,
&print_binary, &print_pointers};

    if (nb != - 1)
        counter += tab[nb](list);
    else
        return (2);
    return (counter);
}
