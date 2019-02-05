/*
** EPITECH PROJECT, 2018
** put unsigned int
** File description:
** display an unsigned int number
*/

#include "my.h"

int put_unsign(unsigned int nb)
{
    unsigned int i = 1;
    int nbchar = 0;

    if (nb == 0) {
        my_putchar('0');
        nbchar++;
        return (nbchar);
    }
    while (nb / i > 0)
        i = i * 10;
    i = i / 10;
    while (i > 0) {
        my_putchar(nb / i % 10 +'0');
        i = i / 10;
        nbchar++;
    }
    return (nbchar);
}
