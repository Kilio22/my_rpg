/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** stats
*/

#include "rpg.h"

void print_stats(obj_t **obj)
{
    for (int i = 0; i < 9; i++) {
        if (i == 1 || i == 4 || i == 5)
            continue;
        my_printf("Character %d\n", i - 1);
        my_printf("Level: %d\n", obj[i]->stats[LEVEL]);
        my_printf("HP: %d\n", obj[i]->stats[HPS]);
        my_printf("ATK: %d\n", obj[i]->stats[ATK]);
        my_printf("DEF: %d\n", obj[i]->stats[DEF]);
    }
    my_printf("\n");
}