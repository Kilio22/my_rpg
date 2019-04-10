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
#include "my_display.h"

#define INVENTORY_SIZE_X 4
#define INVENTORY_SIZE_Y 4
#define INVENTORY_SIZE (4 * 4)

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
    SHIELD,
    OTHER
};

struct item {
    char *name;
    int id;
    int type;
    sfTexture *t;
    int hp;
    int attack;
};
typedef struct item item_t;

struct inventory {
    item_t *stock[INVENTORY_SIZE_X * INVENTORY_SIZE_Y];
    item_t *stuff[6];
    sfRenderWindow *window;
};
typedef struct inventory inventory_t;

// item.c
item_t *item_create(int id, ini_file_t *data);
void item_show_debug(item_t *item);
void item_destroy(item_t *item);

// inventory.c
inventory_t *inventory_create(sfRenderWindow *window);
void inventory_destroy(inventory_t *inv);

// inventory_op.c
int inventory_add_item_to_stock(inventory_t *inv, item_t *item); //0 if fail
void inventory_remove_item_from_stock(inventory_t *inv, item_t *item);
void inventory_add_item_to_stuff(inventory_t *inv, item_t *item, int type);
void inventory_remove_item_from_stuff(inventory_t *inv, int type);

//inventory_swap.c
void inventory_swap_to_stuff(inventory_t *inv, item_t *item, int type);
void inventory_swap_to_stock(inventory_t *inv, int type);

//inventory_debug.c
void inventory_show_debug(inventory_t *inv);
void inventory_show_debug_stuff(inventory_t *inv);
void inventory_show_debug_stock(inventory_t *inv);

#endif /* !INVENTORY_H_ */
