/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** character_gestion
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "rpg.h"

sfBool all_world_hitBox(obj_t *obj, house_t **house)
{
    for (int i = 0; house[i] != NULL; i++)
        if (pp_intersect(obj->sprite, house[i]->hitbox, obj->image, house[i]->image) == 1)
            return (1);
    return (0);
}

void character_control(controls_t *control, obj_t *obj, house_t **house)
{
    sfVector2f newPos = {0, 0};

    if (control->bools[KEYY] == 0) {
        if (control->bools[KEYUP] == 1)
            newPos.y -= 1;
        if (control->bools[KEYDOWN] == 1)
            newPos.y += 1;
        sfSprite_move(obj->sprite, newPos);
        if (all_world_hitBox(obj, house) == 1)
            newPos.y *= -1;
        if (control->bools[KEYLEFT] == 1)
            newPos.x -= 1;
        if (control->bools[KEYRIGHT] == 1)
            newPos.x += 1;
        sfSprite_move(obj->sprite, newPos);
        newPos.y = 0;
        if (all_world_hitBox(obj, house) == 1)
            newPos.x *= -1;
        sfSprite_move(obj->sprite, newPos);
        obj->pos = sfSprite_getPosition(obj->sprite);
    }
}

void follower(obj_t **obj, wind_t *wind)
{
    static sfVector2f oldpos = {0, 0};
    sfVector2f pos = sfSprite_getPosition(obj[1]->sprite);

    if (pos.x > oldpos.x || pos.x < oldpos.x || pos.y > oldpos.y || pos.y < oldpos.y) {
        sfSprite_setPosition(obj[3]->sprite, *(sfVector2f*)wind->list->start->content);
        modif_list(wind->list, obj[1]);
        sfSprite_setPosition(obj[4]->sprite, *(sfVector2f*)wind->list2->start->content);
        modif_list(wind->list2, obj[3]);
    }
    oldpos = sfSprite_getPosition(obj[1]->sprite);
}