/*
** EPITECH PROJECT, 2018
** task03
** File description:
** display the number of characters found in a string
*/

#include <unistd.h>

void my_putchar(char c);

int my_strlen(char const *str)
{
    int nbchar = 0;

    if (str == NULL)
        return (0);
    while (str[nbchar] != '\0') {
        nbchar++;
    }
    return (nbchar);
}
