/*
** EPITECH PROJECT, 2018
** task06
** File description:
** return 1 if number is prime else 0
*/

int my_is_prime(int nb)
{
    int i = 1;
    int compt = 0;

    if (nb <= 1)
        return (0);
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
