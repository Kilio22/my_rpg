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
    for (int i = 1; i < 4 && obj[i] != NULL; i++) {
        free(obj[i]->stats->stats);
        free(obj[i]->stats);
    }
}