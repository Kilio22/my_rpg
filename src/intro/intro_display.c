/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** intro_display
*/

#include "rpg.h"

void display_char(rpg_t *rpg, obj_t **obj)
{
    for (int i = 11; i > 0; i--) {
        if (i == 1 && obj[0]->pos.y > 2396)
            continue;
        if (obj[i] != NULL && i != 4)
            sfRenderWindow_drawSprite(WIND.wind, obj[i]->sprite, NULL);
    }
}