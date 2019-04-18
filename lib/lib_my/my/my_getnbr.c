/*
** EPITECH PROJECT, 2018
** task05
** File description:
** returns number sent to the fonction as a string
*/

#include <unistd.h>

int my_getnbr(char const *str)
{
    long long p = 0;
    int i = 0;
    int result;
    int sign = 1;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            sign = sign * - 1;
        i = i + 1;
    }
    while ((str[i] >= '0' && str[i] <= '9')) {
        result = (p * 10) + (str[i] - '0');
        if ((result != 0) && (result / 10) != p) {
            return 0;
        }
        p = result;
        i++;
    }
    p = p * sign;
    return (p);
}