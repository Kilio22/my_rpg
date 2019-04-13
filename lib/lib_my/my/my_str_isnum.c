/*
** EPITECH PROJECT, 2018
** task11
** File description:
** return 1 ters only contains digits and 0 otherwise
*/

int my_str_isnum(char const *str)
{
    int i = 0;
    int nb = 0;

    if (str[0] == '\0')
        return 1;
    for (i = 0; str[i] != '\0'; i++) {
        if ((str[i] < '0' || str[i] > '9') && str[i] != '-')
            return 0;
        if (str[i] == '-')
            nb++;
    }
    if (nb > 1)
        return 0;
    else
        return 1;
}
