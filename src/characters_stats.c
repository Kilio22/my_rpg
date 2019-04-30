/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** stats
*/

#include "rpg.h"

void print_stats(obj_t **obj)
{
    for (int i = 1; i < 4; i++) {
        my_printf("Character %d\n", i - 1);
        my_printf("Level: %d\n", obj[i]->stats[0]);
        my_printf("HP: %d\n", obj[i]->stats[1]);
        my_printf("ATK: %d\n", obj[i]->stats[2]);
        my_printf("DEF: %d\n", obj[i]->stats[3]);
    }
    my_printf("\n");
}