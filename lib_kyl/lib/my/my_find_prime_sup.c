/*
** EPITECH PROJECT, 2018
** task07
** File description:
** return the smallest prime number
*/

int my_prime(int nb)
{
    int i = 1;
    int compt = 0;

    if (nb <= 1) {
        return (0);
    }
    while (i <= nb) {
        if (nb % i == 0) {
            compt++;
        }
        i++;
    }
    if (compt == 2) {
        return (1);
    } else {
        return (0);
    }
    return (0);
}

int my_find_prime_sup(int nb)
{
    while (my_prime(nb) != 1) {
        nb++;
    }
    return (nb);
}
