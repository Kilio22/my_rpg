/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** inventory
*/

#ifndef INVENTORY2_H_
#define INVENTORY2_H_

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "my_vector.h"
#include "my_dragndrop.h"
#include <stdlib.h>
#include "macros.h"
#include "my_str.h"
#include "my_ini.h"

enum data_mapping {
    NAME,
    TYPE,
    ASSET,
    HP,
    ATTACK
};

enum items {
    WEAPON = 0,
    HELMET,
    ARMOR,
    PANTS,
    BOOTS,
    SHIELD
};

struct item {
    char *name;
    int id;
    int type;
    sfSprite *sprite;
    int hp;
    int attack;
};
typedef struct item item_t;

// item.c
item_t *item(int id, ini_file_t *data);
void item_show_debug(int id, ini_file_t *data);
void item_destroy(item_t *item);

#endif /* !INVENTORY_H_ */
