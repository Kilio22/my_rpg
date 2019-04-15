/*
** EPITECH PROJECT, 2019
** test
** File description:
** struct
*/

#include <SFML/Audio.h>

#ifndef STRUCT_H_
#define STRUCT_H_
#include <SFML/Graphics.h>
#include "my_vector.h"
#include "stdbool.h"

enum menu_type {
    BACK,
    LOAD
};

enum obj_type {
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
} wind_t;

typedef struct obj_s {
    sfImage *image;
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect sprite_rect;
    sfVector2f pos;
    sfVector2f oldPos;
    sfClock *clock;
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
    int auberge;
    int language;
    sfMusic *back_music;
    simple_vector_t *follower;
    simple_vector_t *follower2;
} game_t;

typedef struct button_s {
    sfSprite *sprite;
    int state;
} button_t;

typedef struct fields_s {
    sfText *text;
    int status;
} fields_t;

typedef struct controls_s {
    int wait_key;
    int *keys;
    sfBool *bools;
    sfVector2f mousePos;
    fields_t text[6];
    sfSprite *back;
} controls_t;

typedef struct settings_s {
    int high;
    int volume;
    sfRectangleShape *rect;
    button_t buttons[5];
    fields_t text[4];
} settings_t;

typedef struct load_game_s {
    fields_t text[3];
    sfRectangleShape *rect;
    sfSprite *back;
    int high;
} load_game_t;

typedef struct menu_s {
    sfClock *clock;
    bool menu_on;
    sfSprite *menu_sprite[2];
    fields_t buttons[6];
    int highlight;
    sfRectangleShape *rect;
    sfText *descr_text;
} menu_t;

typedef struct first_gid_s
{
    int gid;
    char *path;
    int offset;
} first_gid_t;

typedef struct layer_s
{
    int **map;
    int width;
    int height;
} layer_t;

typedef struct sprite_s
{
    int id;
    sfSprite *sprite;
    sfVector2f **pos;
} sprite_t;

typedef struct map_s {
    first_gid_t *gid[4];
    layer_t *layers[5];
    sprite_t *sprite[715];
} map_t;

typedef struct rpg_s {
    controls_t controls;
    game_t game;
    wind_t wind;
    menu_t menu;
    map_t map;
} rpg_t;

#endif /* !STRUCT_H_ */