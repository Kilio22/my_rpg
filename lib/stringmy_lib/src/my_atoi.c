/*
** EPITECH PROJECT, 2018
** my_atoi
** File description:
** convert str to int
*/

#include "my_str.h"

static int s_pow(int nb, int power)
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

static int s_str_isneg(char const *str)
{
    if (my_str_isnum(str) == 0)
        return -1;
    if (str[0] == '-')
        return 1;
    return 0;
}

int my_atoi(char const *str)
{
    int neg_flag = (s_str_isneg(str) == 1) ? 1 : 0;
    int size = my_strlen(str) - neg_flag;
    int result = 0;

    for (int i = 1; i < size + 1; i++){
        char c = str[size - i + neg_flag];
        int nb = (c - '0') * s_pow(10, i - 1);
        result += nb;
    }
    result = (neg_flag == 1) ? result * -1 : result;
    return (result);
}
