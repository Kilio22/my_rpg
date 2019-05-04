/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** display_utils
*/

#include "rpg.h"

void print_reverse_order(obj_t **obj, rpg_t *rpg)
{
    for (int i = 1; i < 12; i++)
        if (obj[i] != NULL && i != 4)
            sfRenderWindow_drawSprite(WIND.wind, obj[i]->sprite, NULL);
}

void print_base_order(obj_t **obj, rpg_t *rpg)
{
    for (int i = 11; i > 0; i--)
        if (obj[i] != NULL && i != 4)
            sfRenderWindow_drawSprite(WIND.wind, obj[i]->sprite, NULL);
}