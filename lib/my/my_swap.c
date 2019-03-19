/*
** EPITECH PROJECT, 2018
** task01
** File description:
** swap 2 numbers with pointers
*/

#include <unistd.h>

int my_putchar(char c);

void my_swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
