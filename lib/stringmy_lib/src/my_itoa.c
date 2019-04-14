/*
** EPITECH PROJECT, 2018
** mg_iota
** File description:
** convert int to char
*/

#include "mg_str.h"

static long counter_set(int nb)
{
    long counter = 10000000000000;

    while (counter > nb)
        counter = counter / 10;
    return (counter);
}

static int malloc_size(int nb)
{
    int size = 0;

    if (nb == 0)
        return (1);
    if (nb < 0) {
        nb = nb * -1;
        size++;
    }
    while (nb != 0) {
        size++;
        nb = nb / 10;
    }
    return (size);
}

char *mg_itoa(int nb)
{
    char *buff = malloc(sizeof(int) * (malloc_size(nb) + 1));
    int i = (nb < 0) ? 1 : 0;
    long counter = counter_set(nb);

    if (!buff)
        return (NULL);
    if (nb < 0)
        buff[0] = '-';
    if (nb == 0) {
        buff[0] = '0';
        buff[1] = '\0';
        return (buff);
    }
    for (; counter != 0; i++) {
        buff[i] = nb / counter + 48;
        nb = nb - (nb / counter * counter);
        counter = counter / 10;
    }
    buff[i] = '\0';
    return (buff);
}