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
        if (house->tab[i] == NULL) {
            house = NULL;
            return;
        }
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
    house->door_use_rectangle = sfRectangleShape_create();
    house->door_rect = rect;
    house->frame_animation = 0;
    sfRectangleShape_setSize(house->door_use_rectangle, V2F(1, 16));
    sfRectangleShape_setOrigin(house->door_use_rectangle, V2F(0.5, 14));
    sfRectangleShape_setPosition(house->door_use_rectangle,
    V2F(pos.x + rect.width / 2, pos.y + rect.height));
    house->door_use_rect_bound =
sfRectangleShape_getGlobalBounds(house->door_use_rectangle);
    sfSprite_setTexture(house->tab[DOOR], house->doorTexture, sfTrue);
    sfSprite_setPosition(house->tab[DOOR], pos);
    sfSprite_setTextureRect(house->tab[DOOR], rect);
}

house_t *create_house(int type, sfVector2f pos)
{
    house_t *house = malloc(sizeof(house_t));
    sfVector2f doorPos =
{pos.x + door_pos[type].x, pos.y + door_pos[type].y};

    if (house == NULL)
        return NULL;
    house_creation(house, (char *)house_path[type], pos, house_rects[type]);
    if (house == NULL)
        return NULL;
    door_creation(house, "assets/doors.png", doorPos, door_rects[type]);
    house->type = type;
    return (house);
}

int create_houses(house_t **house)
{
    int index[NB_HOUSE] = {AUBERGE, FORGE, MAISON1, MAISON2, EGLISE, MAISON5,
MAISON1, MAISON3, MAISON2, MAISON4, MAISON3,
MAISON3, MAISON5, MAISON1, MAISON5};
    sfVector2f vect[NB_HOUSE] = {{9840, 1088}, {10160, 1184}, {11840, 1088},
{10384, 1280}, {10912, 800}, {11414, 1024}, {11658, 1088}, {11136, 1312},
{11524, 1344}, {11126, 1600}, {11360, 1600}, {10280, 1600}, {9700, 1600},
{9320, 1800}, {9400, 920}};
    int i = 0;

    for (i = 0; i < NB_HOUSE; i++) {
        house[i] = create_house(index[i], vect[i]);
        if (house[i] == NULL)
            return -1;
    }
    house[i] = NULL;
    return 0;
}