/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** display_utils
*/

#include "rpg.h"

int free_display(int display[12])
{
    for (int i = 0; i < 12; i++)
        if (display[i] == -1)
            return i;
    return -1;
}

int is_in_display(int index, int display[12])
{
    for (int i = 0; i < 12; i++) {
        if (display[i] == index)
            return 1;
    }
    return 0;
}