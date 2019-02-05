/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** create_house
*/

#include <stdlib.h>
#include "proto.h"
#include "struct.h"
#include "printf.h"

void house_interaction(obj_t *obj, house_t **house)
{
    obj->sprite_rect = f_to_i_rect(sfSprite_getGlobalBounds(obj->sprite));

    for (int i = 0; house[i] != NULL; i++) {
        house[i]->door_rect = f_to_i_rect(sfSprite_getGlobalBounds(house[i]->door));
        if (sfIntRect_intersects(&obj->sprite_rect, &house[i]->door_rect, NULL) == 1)
            my_printf ("touche\n");
    }
}

void house_creation(house_t *house, char *path, sfVector2f pos, sfIntRect rect)
{
    house->image = sfImage_createFromFile(path);
    house->houseTexture = sfTexture_createFromFile(path, NULL);
    house->interior = sfSprite_create();
    house->wall = sfSprite_create();
    house->roof = sfSprite_create();
    sfSprite_setTexture(house->interior, house->houseTexture, sfTrue);
    sfSprite_setTexture(house->wall, house->houseTexture, sfTrue);
    sfSprite_setTexture(house->roof, house->houseTexture, sfTrue);
    sfSprite_setTextureRect(house->interior, rect);
    rect.left += rect.width;
    sfSprite_setTextureRect(house->roof, rect);
    rect.left += rect.width;
    sfSprite_setTextureRect(house->wall, rect);
    sfSprite_setPosition(house->interior, pos);
    sfSprite_setPosition(house->wall, pos);
    sfSprite_setPosition(house->roof, pos);
}

void door_creation(house_t *house, char *path, sfVector2f pos, sfIntRect rect)
{
    house->door = sfSprite_create();
    house->doorTexture = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(house->door, house->doorTexture, sfTrue);
    sfSprite_setPosition(house->door, pos);
    sfSprite_setTextureRect(house->door, rect);
}

house_t *create_house(int type, sfVector2f housePos)
{
    house_t *house = malloc(sizeof(house_t));
    char *housePath;
    char *doorPath;
    sfIntRect houseRect;
    sfIntRect doorRect;
    sfVector2f doorPos;

    if (type == 1) {
        housePath = "assets/maison 1.png";
        doorPath = "assets/door1.png";
        houseRect = (sfIntRect){0, 0, 192, 320};
        doorRect = (sfIntRect){0, 0, 96, 96};
        doorPos = (sfVector2f){housePos.x + 0, housePos.y + 256};
    }
    else if (type == 2) {
        housePath = "assets/maison 2.png";
        doorPath = "assets/door1.png";
        houseRect = (sfIntRect){0, 0, 256, 256};
        doorRect = (sfIntRect){0, 0, 96, 96};
        doorPos = (sfVector2f){housePos.x + 0, housePos.y + 192};
    }
    house_creation(house, housePath, housePos, houseRect);
    door_creation(house, doorPath, doorPos, doorRect);
    return (house);
}