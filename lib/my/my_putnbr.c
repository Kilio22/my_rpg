/*
** EPITECH PROJECT, 2018
** my_putnbr
** File description:
** description
*/

#include "my.h"

int my_putnbr(int nb)
{
    if (nb < 0 && nb != -2147483648) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb >= 10 && nb != -2147483648) {
        my_putnbr(nb / 10);
        my_putchar(nb % 10 + '0');
    } else if (nb != -2147483648) {
        my_putchar(nb + '0');
    }
    if (nb == -2147483648) {
        my_putchar('-');
        my_putchar('2');
        my_putnbr(147483648);
    }
    return (0);
}
