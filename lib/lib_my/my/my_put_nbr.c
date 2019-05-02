/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** display every numbers of an int
*/

void my_putchar(char c);

int my_put_nbr(int nb)
{
    int i = 1;
    int nbchar = 0;

    if (nb == 0) {
        my_putchar('0');
        nbchar++;
        return (nbchar);
    }
    else if (nb < 0) {
        my_putchar('-');
        nb *= (-1);
    }
    while (nb / i > 0)
        i = i * 10;
    i = i / 10;
    for (; i > 0; nbchar++) {
        my_putchar(nb / i % 10 + '0');
        i = i / 10;
    }
    return (nbchar);
}
