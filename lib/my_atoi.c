/*
** EPITECH PROJECT, 2018
** my_atoi
** File description:
** int into char
*/

#include "my.h"

int my_atoi(char *input)
{
    int i = 0;
    int lenght = my_strlen(input);
    int result = 0;

    for (;i < lenght; i++) {
        result *= 10;
        result += (input[i] - '0');
    }
    return (result);
}