/*
** EPITECH PROJECT, 2019
** test
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_
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

enum stats {
    LEVEL = 0,
    HP,
    ATK,
    DEF
};

typedef struct char_stats_s {
    int *stats;
} char_stats_t;

typedef struct wind_s {
    sfRenderWindow *wind;
    sfVector2u windSize;
    sfEvent event;
    sfView *view;
    simple_vector_t *list; //a retirer plus tard
    simple_vector_t *list2; //a retirer plus tard
    int fd; //a retirer plus tard
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
    char_stats_t *stats;
} obj_t;

typedef struct house_s {
    sfImage *image;
    sfImage *door_image;
    sfTexture *houseTexture;
    sfTexture *doorTexture;
    sfSprite *interior;
    sfSprite *hitbox;
    sfSprite *wall;
    sfSprite *roof;
    sfSprite *door;
    sfIntRect door_rect;
    sfBool display_house;
    int frame_animation;
} house_t;

typedef struct game_s {
    int nb_save;
} game_t;

typedef struct rph_s {
    controls_t controls;
    game_t game;
    wind_t wind;
} rpg_t;

#endif /* !STRUCT_H_ */