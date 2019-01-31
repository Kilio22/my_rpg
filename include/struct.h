/*
** EPITECH PROJECT, 2019
** test
** File description:
** struct
*/

#pragma once
#include <SFML/Graphics.h>

typedef struct wind_s {
    sfRenderWindow *wind;
    sfVector2u windSize;
    sfEvent event;
    sfView *view;
    sfRectangleShape *house_1;
} wind_t;

typedef struct myBool_s {
    sfBool keyUp;
    sfBool keyDown;
    sfBool keyLeft;
    sfBool keyRight;
    sfBool keySpace;
    sfBool keyY;
    sfBool zoom;
    sfBool deZoom;
    sfVector2f mousePos;
} myBool_t;

typedef struct obj_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfImage *image;
    sfVector2f pos;
    sfIntRect sprite_rect;
    int id;
} obj_t;

typedef struct house_s {
    sfImage *image;
    sfTexture *houseTexture;
    sfTexture *doorTexture;
    sfSprite *interior;
    sfSprite *wall;
    sfSprite *roof;
    sfSprite *door;
} house_t;