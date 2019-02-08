/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** display_and_obj
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "proto.h"
#include "struct.h"

obj_t *create_object(char *Path, sfVector2f pos, sfIntRect intrect, sfBool centered)
{
    obj_t *obj = malloc(sizeof(obj_t));
    sfFloatRect rect;

    obj->image = sfImage_createFromFile(Path);
    obj->texture = sfTexture_createFromFile(Path, NULL);
    obj->sprite = sfSprite_create();
    obj->pos = pos;
    obj->sprite_rect = intrect;
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

void display(wind_t *wind, obj_t **obj, house_t **house)
{
    sfRenderWindow_setView(wind->wind, wind->view);
    sfRenderWindow_drawSprite(wind->wind, obj[0]->sprite, NULL); //ground
    sfRenderWindow_drawSprite(wind->wind, obj[1]->sprite, NULL); //hero_hitBox
    for (int i = 0; house[i] != NULL; i++) {
        sfRenderWindow_drawSprite(wind->wind, house[i]->interior, NULL); //house_Interior
        sfRenderWindow_drawSprite(wind->wind, house[i]->wall, NULL); //house_Wall
        sfRenderWindow_drawSprite(wind->wind, house[i]->door, NULL); //house_Door
    }
    for (int i = 2; obj[i] != NULL; i++)
        sfRenderWindow_drawSprite(wind->wind, obj[i]->sprite, NULL); //obj
    for (int i = 0; house[i] != NULL; i++)
        sfRenderWindow_drawSprite(wind->wind, house[i]->roof, NULL); //house_Roof
    sfRenderWindow_display(wind->wind);
    sfRenderWindow_clear(wind->wind, sfBlack);
}
