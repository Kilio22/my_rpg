/*
** EPITECH PROJECT, 2018
** my_putfloat
** File description:
** display an float
*/

#include "my_display.h"

static int pow_s(int nb, int power)
{
    int res = nb;

    if (power == 0)
        return (1);
    if (power < 0)
        return (0);
    for (int i = 0; i < power - 1; i++){
        int tampon = nb * res;
        if (tampon / nb == res)
            res = tampon;
        else
            return (0);
    }
    return (res);
}

void my_putfloat(float nb, int sensibility)
{
    if (nb < 0){
        nb = nb * -1;
        my_putchar('-');
    }
    my_putnbr((int)nb);
    if (sensibility == 0)
        return;
    nb -= (int)nb;
    nb = nb *pow_s(10, sensibility);
    my_putchar('.');
    if ((int)nb == 0){
        my_putchar('0');
    }
    my_putnbr((int)nb);
}
