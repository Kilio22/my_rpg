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

void display(rpg_t *rpg, obj_t **obj, house_t **house)
{
    sfRenderWindow_setView(WIND.wind, WIND.view);
    sfRenderWindow_drawSprite(WIND.wind, obj[0]->sprite, NULL); //ground
    sfRenderWindow_drawSprite(WIND.wind, obj[1]->sprite, NULL); //hero_hitBox
    for (int i = 0; house[i] != NULL; i++) {
        sfRenderWindow_drawSprite(WIND.wind, house[i]->interior, NULL); //house_Interior
        if (house[i]->display_house == 1) {
            sfRenderWindow_drawSprite(WIND.wind, house[i]->wall, NULL); //house_Wall
            sfRenderWindow_drawSprite(WIND.wind, house[i]->door, NULL); //house_Door
        }
    }
    for (int i = 4; i > 1; i--)
        sfRenderWindow_drawSprite(WIND.wind, obj[i]->sprite, NULL); //obj
    for (int i = 0; house[i] != NULL; i++)
        if (house[i]->display_house == 1)
            sfRenderWindow_drawSprite(WIND.wind, house[i]->roof, NULL); //house_Roof
    sfRenderWindow_display(WIND.wind);
    sfRenderWindow_clear(WIND.wind, sfBlack);
}
