/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** inventory_update_stats
*/

#include "rpg.h"

void update_inventory_stats(rpg_t *rpg, obj_t **obj)
{
    int j = 0;

    for (int i = 0; i < 4; i++) {
        if (i == 1)
            continue;
        GAME.inv->stats[j][0] = obj[i]->stats[HPS];
        GAME.inv->stats[j][1] = obj[i]->stats[ATK];
        GAME.inv->stats[j][2] = obj[i]->stats[DEF];
        GAME.inv->stats[j][3] = obj[i]->stats[SPEED];
        j++;
    }
}