/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2018
** File description:
** randomiser
*/

#include <stdlib.h>
#include <time.h>

int randomiser(int max)
{
    int result = 0;

    srand(1);
    result = rand() % max;
    return (result);
}