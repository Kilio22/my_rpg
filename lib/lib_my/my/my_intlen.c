/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** my_intlen
*/

int my_intlen(int nb)
{
    int counter = 0;

    if (nb < 0)
        counter++;
    while (nb != 0) {
        nb = nb / 10;
        counter++;
    }
    if (counter == 0)
        counter++;
    return (counter);
}
