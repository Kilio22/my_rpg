/*
** EPITECH PROJECT, 2018
** my_count_line
** File description:
** my_count_line
*/

#include "my_str.h"

int my_count_line(char const *str)
{
    int i = 0;
    int counter = 0;

    while (str[i] != '\0'){
        counter = (str[i] == '\n') ? counter + 1 : counter;
        i++;
    }
    return (counter + 1);
}
