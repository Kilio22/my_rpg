/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** create_house
*/

#include <stdlib.h>
#include <stdio.h>
#include "rpg.h"

void house_creation(house_t *house, char *path, sfVector2f pos, sfIntRect rect)
{
    house->image = sfImage_createFromFile(path);
    sfTexture *houseTexture = sfTexture_createFromFile(path, NULL);
    house->display_house = 1;

    for (int i = 0; i < 4; i++) {
        house->tab[i] = malloc(sizeof(sfSprite *));
        house->tab[i] = sfSprite_create();
        sfSprite_setTexture(house->tab[i], houseTexture, sfTrue);
        sfSprite_setTextureRect(house->tab[i], rect);
        rect.left += rect.width;
        sfSprite_setPosition(house->tab[i], pos);
    }
}

void door_creation(house_t *house, char *path, sfVector2f pos, sfIntRect rect)
{
    house->tab[DOOR] = sfSprite_create();
    house->door_image = sfImage_createFromFile(path);
    house->doorTexture = sfTexture_createFromFile(path, NULL);
    house->door_rect = rect;
    house->frame_animation = 0;
    sfSprite_setTexture(house->tab[DOOR], house->doorTexture, sfTrue);
    sfSprite_setPosition(house->tab[DOOR], pos);
    sfSprite_setTextureRect(house->tab[DOOR], rect);
}

house_t *create_house(int type, sfVector2f pos)
{
    house_t *house = malloc(sizeof(house_t));
    sfVector2f doorPos = {pos.x + 0, pos.y + door_pos[type]};

    house_creation(house, (char *)house_path[type], pos, house_rects[type]);
    door_creation(house, (char *)door_path[type], doorPos, door_rects);
    return (house);
}