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
} wind_t;

enum {
    KEYUP = 0,
    KEYDOWN,
    KEYLEFT,
    KEYRIGHT,
    KEYSPACE,
    ZOOM,
    DEZOOM,
    KEYY
};

typedef struct controls_s {
    int *keys;
    sfBool *bools;
    sfVector2f mousePos;
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
    sfIntRect door_rect;
} house_t;

#endif //STRUCT_H