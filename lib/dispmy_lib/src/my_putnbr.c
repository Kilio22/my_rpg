/*
** EPITECH PROJECT, 2018
** mg_putnbr
** File description:
** display all value of an int
*/

#include "my_display.h"

int mg_putnbr(int nb)
{
    if (nb < 0){
        mg_putchar('-');
        nb = nb * -1;
    }
    if (nb >= 10){
        int mod = nb % 10;
        nb = (nb - mod) / 10;
        mg_putnbr(nb);
        mg_putchar(48 + mod);
    } else {
        mg_putchar(nb + '0');
    }
    return nb;
}

void mg_putunbr(unsigned int nb)
{
    if (nb >= 10){
        int mod = nb % 10;
        nb = (nb - mod) / 10;
        mg_putunbr(nb);
        mg_putchar(48 + mod);
    } else {
        mg_putchar(nb + '0');
    }
}