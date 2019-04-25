/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** camera_gestion
*/

#include "rpg.h"

void camera_control(rpg_t *rpg, sfVector2f pos, obj_t **obj)
{
    if (CONTROLS.bools[KEYY] == 0)
        sfView_setCenter(WIND.view, pos);
    else {
        if (CONTROLS.bools[KEYRIGHT] == 1)
            sfView_move(WIND.view, (sfVector2f){10, 0});
        if (CONTROLS.bools[KEYLEFT] == 1)
            sfView_move(WIND.view, (sfVector2f){-10, 0});
        if (CONTROLS.bools[KEYDOWN] == 1)
            sfView_move(WIND.view, (sfVector2f){0, 10});
        if (CONTROLS.bools[KEYUP] == 1)
            sfView_move(WIND.view, (sfVector2f){0, -10});
    }
    if (CONTROLS.bools[KEYSPACE] == 1)
        sfSprite_setPosition(obj[HERO_HB]->sprite, sfView_getCenter(WIND.view));
}