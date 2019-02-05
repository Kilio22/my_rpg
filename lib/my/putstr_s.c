/*
** EPITECH PROJECT, 2018
** task02
** File description:
** display one by one the characters of a string
*/

#include <unistd.h>
#include "my.h"
#include "printf.h"

int my_putstr_s(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 32 || str[i] >= 127) {
            my_putchar('\\');
            put_octal_d(str[i]);
            i++;
        }
        my_putchar(str[i]);
        i++;
    }
    return (i - 1);
}
