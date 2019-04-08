/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** display_and_obj
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "rpg.h"

obj_t *create_object(char *Path, sfVector2f pos, sfIntRect intrect,
sfBool centered)
{
    obj_t *obj = malloc(sizeof(obj_t));
    sfFloatRect rect;

    obj->image = sfImage_createFromFile(Path);
    obj->texture = sfTexture_createFromFile(Path, NULL);
    obj->sprite = sfSprite_create();
    obj->pos = pos;
    obj->sprite_rect = intrect;
    obj->frame_animation = 0;
    obj->clock = sfClock_create();
    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    sfSprite_setTextureRect(obj->sprite, intrect);
    sfSprite_setPosition(obj->sprite, pos);
    if (centered == 1) {
        rect = sfSprite_getGlobalBounds(obj->sprite);
        sfSprite_setOrigin(obj->sprite, (sfVector2f)
        {rect.width / 2, rect.height / 2});
    }
    return (obj);
}