/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** animation
*/

#include <SFML/Graphics.h>
#include "rpg.h"

static void character_orientation(obj_t *obj)
{
    obj->oldPos = sfSprite_getPosition(obj->sprite);

    if (obj->oldPos.x < obj->pos.x)
        obj->sprite_rect.top = 64;
    else if (obj->oldPos.x > obj->pos.x)
        obj->sprite_rect.top = 0;
    else if (obj->oldPos.y > obj->pos.y) {
        obj->sprite_rect.top = 128;
        if (obj->sprite_rect.left >= 128)
            obj->sprite_rect.left = 0;
    }
    else if (obj->oldPos.y < obj->pos.y) {
        obj->sprite_rect.top = 192;
        if (obj->sprite_rect.left >= 128)
            obj->sprite_rect.left = 0;
    }
    else
        obj->sprite_rect.left = 0;
    obj->pos = sfSprite_getPosition(obj->sprite);
}

static void character_animation(obj_t *obj)
{
    if (obj->frame_animation > 8) {
        animation(&obj->sprite_rect, 32, 32, 160);
        obj->frame_animation = 0;
    }
    obj->frame_animation++;
    character_orientation(obj);
}

void all_character_animation(obj_t **obj)
{
    for (int i = 2; obj[i] != NULL; i ++)
        character_animation(obj[i]);
}

void update_all_rect(obj_t **obj, house_t **house)
{
    for (int i = 0; obj[i] != NULL; i++)
        sfSprite_setTextureRect(obj[i]->sprite, obj[i]->sprite_rect);
    for (int i = 0; obj[i] != NULL; i++)
        sfSprite_setTextureRect(house[i]->door, house[i]->door_rect);
}