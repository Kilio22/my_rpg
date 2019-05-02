/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** printf
*/

#include <stdarg.h>
#include "my.h"
#include "printf.h"

int my_printf(char *str, ...)
{
    va_list list;
    int nb = 0;

    va_start(list, str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '%' && check(str[i + 1]) != - 1) {
            nb += printer(str[i + 1], list);
            i++;
        }
        else if (str[i] == '%' && str[i + 1] == '%') {
            my_putchar(str[++i]);
            nb++;
        }
        else {
            my_putchar(str[i]);
            nb++;
        }
    }
    va_end(list);
    return (nb);
}
