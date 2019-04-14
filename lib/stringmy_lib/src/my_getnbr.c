/*
** EPITECH PROJECT, 2018
** mg_getnbr
** File description:
** mg_getnbr
*/

#include "mg_str.h"

static int get_that_string_length(char const *str)
{
    int i = 0;

    while (*(str + i) != '\0') {
        i++;
    }
    return (i);
}

static int get_return_value(int is_negative, long long result)
{
    if (is_negative%2 == 1) {
        result = result * -1;
    }
    if (result < -2147483648 || result > 2147483647)
        return (0);
    return (result);
}

int mg_getnbr(char const *str)
{
    int i = 0;
    long long result = 0;
    int is_result_negative = 0;
    int length = get_that_string_length(str);

    while (str[i] < '0' || str[i] > '9') {
        if ((str[i] - '-') == 0)
            is_result_negative++;
        if (str[i] != '-' && str[i] != '+')
            return (0);
        i++;
    }
    while (i < length && (str[i] >= '0' && str[i] <= '9')) {
        long long x = result * 10 + (str[i] - '0');
        if ((result != 0) && ((x / result) != (10 + ((str[i] - '0') / result))))
            return (0);
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return (get_return_value(is_result_negative, result));
}
