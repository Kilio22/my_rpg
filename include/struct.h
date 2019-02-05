/*
** EPITECH PROJECT, 2019
** test
** File description:
** struct
*/

#ifndef STRUCT_H
#define STRUCT_H
#include <SFML/Graphics.h>

enum {
    UP = 0,
    LEFT,
    DOWN,
    RIGHT,
    INTERACT
};

typedef struct wind_s {
    sfRenderWindow *wind;
    sfVector2u windSize;
    sfEvent event;
    sfView *view;
    sfRectangleShape *house_1;
} wind_t;

typedef struct controls_s {
    sfBool keyUp;
    sfBool keyDown;
    sfBool keyLeft;
    sfBool keyRight;
    sfBool keySpace;
    sfBool keyY;
    sfBool zoom;
    sfBool deZoom;
    sfVector2f mousePos;
    int *keys;
} controls_t;

typedef struct obj_s {
    sfImage *image;
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect sprite_rect;
    sfVector2f pos;
    sfBool outside;
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

#endif //STRUCT_H