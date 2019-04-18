/*
** EPITECH PROJECT, 2018
** task04
** File description:
** same as task03 but using recursive fonction
*/

int my_compute_power_rec(int nb, int p)
{
    long a = 0;

    if (p < 0) {
        return 0;
    }
    if (p == 0) {
        return 1;
    }
    if (p == 1) {
        return (nb);
    }
    a = (my_compute_power_rec(nb, (p - 1)));
    a *= nb;
    if (a > 2147483647 || a < -2147483648) {
        return 0;
    }
    return (a);
}
