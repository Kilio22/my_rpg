/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** animation
*/

#include <SFML/Graphics.h>
#include "rpg.h"

static void character_orientation_pnj(obj_t *obj)
{
    if (obj->oldPos.x > obj->pos.x) {
        obj->sprite_rect.top = 64;
        return;
    }
    if (obj->oldPos.x < obj->pos.x) {
        obj->sprite_rect.top = 0;
        return;
    }
    if (obj->oldPos.y < obj->pos.y) {
        obj->sprite_rect.top = 128;
        if (obj->sprite_rect.left >= 128)
            obj->sprite_rect.left = 0;
    } else if (obj->oldPos.y > obj->pos.y) {
        obj->sprite_rect.top = 192;
        if (obj->sprite_rect.left >= 128)
            obj->sprite_rect.left = 0;
    } else
        obj->sprite_rect.left = 0;
}

static void character_orientation(obj_t *obj)
{
    if (obj->oldPos.x < obj->pos.x) {
        obj->sprite_rect.top = 64;
        return;
    }
    if (obj->oldPos.x > obj->pos.x) {
        obj->sprite_rect.top = 0;
        return;
    }
    if (obj->oldPos.y > obj->pos.y) {
        obj->sprite_rect.top = 128;
        if (obj->sprite_rect.left >= 128)
            obj->sprite_rect.left = 0;
    } else if (obj->oldPos.y < obj->pos.y) {
        obj->sprite_rect.top = 192;
        if (obj->sprite_rect.left >= 128)
            obj->sprite_rect.left = 0;
    } else
        obj->sprite_rect.left = 0;
}

static void character_animation(obj_t *obj, int i)
{
    if (obj->frame_animation > 8) {
        animation(&obj->sprite_rect, 32, 32, 160);
        obj->frame_animation = 0;
    }
    obj->frame_animation += update_time(NULL);
    if (i < 6 || i == 11) {
        obj->oldPos = sfSprite_getPosition(obj->sprite);
        character_orientation(obj);
    }
    if (i >= 6 && i != 11) {
        character_orientation_pnj(obj);
        obj->oldPos = sfSprite_getPosition(obj->sprite);
    }
    obj->pos = sfSprite_getPosition(obj->sprite);
}

void all_character_animation(obj_t **obj)
{
    for (int i = 1; i < 12; i++)
        if (obj[i] != NULL)
            character_animation(obj[i], i);
}

void update_all_rect(obj_t **obj, house_t **house)
{
    for (int i = 0; i < 12; i++)
        if (obj[i] != NULL)
            sfSprite_setTextureRect(obj[i]->sprite, obj[i]->sprite_rect);
    for (int i = 0; house[i] != NULL; i++)
        sfSprite_setTextureRect(house[i]->tab[DOOR], house[i]->door_rect);
}