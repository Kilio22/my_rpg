/*
** EPITECH PROJECT, 2019
** test
** File description:
** struct
*/

#ifndef STRUCT_H
#define STRUCT_H
#include <SFML/Graphics.h>
#include "my_vector.h"

enum keys {
    UP = 0,
    LEFT,
    DOWN,
    RIGHT,
    INTERACT,
    STATS
};

enum bools {
    KEYUP = 0,
    KEYDOWN,
    KEYLEFT,
    KEYRIGHT,
    KEYSPACE,
    ZOOM,
    DEZOOM,
    KEYINTER,
    KEYY
};

typedef struct wind_s {
    sfRenderWindow *wind;
    sfVector2u windSize;
    sfEvent event;
    sfView *view;
    simple_vector_t *list; //a retirer plus tard
    simple_vector_t *list2; //a retirer plus tard
} wind_t;

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
    sfVector2f oldPos;
    int frame_animation;
} obj_t;

typedef struct house_s {
    sfImage *image;
    sfImage *door_image;
    sfTexture *houseTexture;
    sfTexture *doorTexture;
    sfSprite *interior;
    sfSprite *wall;
    sfSprite *roof;
    sfSprite *door;
    sfIntRect door_rect;
    int frame_animation;
} house_t;

#endif //STRUCT_H