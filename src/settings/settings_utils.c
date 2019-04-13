/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** settings_utils
*/

#include "rpg.h"

int check_high_controls(int i)
{
    static int value = 0;

    if (i == -1)
        return (value);
    value = i;
    return -1;
}