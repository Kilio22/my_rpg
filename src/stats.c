/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** stats
*/

#include "my.h"
#include "struct.h"
#include "printf.h"

void print_stats(obj_t **obj)
{
    for (int i = 2; i < 5; i++) {
        my_printf("Character %d\n", i - 1);
        my_printf("Level: %d\n", obj[i]->stats->stats[0]);
        my_printf("HP: %d\n", obj[i]->stats->stats[1]);
        my_printf("ATK: %d\n", obj[i]->stats->stats[2]);
        my_printf("DEF: %d\n", obj[i]->stats->stats[3]);
    }
}