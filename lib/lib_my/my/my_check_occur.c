/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** my_check_occur
*/

#include "my.h"

int my_check_occur2(char *str, char c)
{
    int i = 0;

    for (i = 0; str[i] != 't' && str[i] != '\0'; i++);
    for (; str[i] != '\0'; i++) {
        if (str[i] == c)
            return 1;
    }
    return 0;
}

int my_check_occur(char *str, char c)
{
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] == c)
            return 1;
    }
    return 0;
}