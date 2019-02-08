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

void house_interaction(obj_t *obj, controls_t *control, house_t **house)
{
    sfIntRect rectReset = {0, 0, 0, 0};

    for (int i = 0; house[i] != NULL; i++) {
        if (pp_intersect(obj->sprite, house[i]->door, obj->image, house[i]->door_image) == 1 && control->bools[KEYINTER] == 1) {
            if (house[i]->frame_animation == 8 && house[i]->door_rect.left < 384 - 96) {
                animation(&house[i]->door_rect, 0, 96, 384);
                house[i]->frame_animation = 0;
            }
            else if (house[i]->door_rect.left > 384 - 97)
                control->bools[KEYINTER] = 0;
            house[i]->frame_animation ++;
            sfSprite_setTextureRect(house[i]->roof, rectReset);
            sfSprite_setTextureRect(house[i]->wall, rectReset);
        }
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
    house->door_image = sfImage_createFromFile(path);
    house->doorTexture = sfTexture_createFromFile(path, NULL);
    house->door_rect = rect;
    house->frame_animation = 0;
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