/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** free_save
*/

#include "rpg.h"

void free_save(obj_t **obj, rpg_t *rpg)
{
    free(CONTROLS.keys);
    for (int i = 2; i < 5; i++) {
        free(obj[i]->stats->stats);
        free(obj[i]->stats);
    }
}