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
#include "stdbool.h"

enum obj_type {
    GROUND,
    HERO_HB
};

enum house_parts {
    HITBOX,
    INTERIOR,
    WALL,
    ROOF,
    DOOR
};

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
    sfVector2f mouse_pos;
    bool click;
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
    sfTexture *doorTexture;
    sfSprite *tab[5];
    sfIntRect door_rect;
    sfBool display_house;
    int frame_animation;
} house_t;

typedef struct game_s {
    int nb_save;
} game_t;

typedef struct menu_s {
    bool menu_on;
} menu_t;

typedef struct rpg_s {
    controls_t controls;
    game_t game;
    wind_t wind;
    menu_t menu;
} rpg_t;

#endif /* !STRUCT_H_ */