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
#include "mg_str.h"
#include "my_ini.h"
#include "my_display.h"

#define INVENTORY_SIZE_X 9
#define INVENTORY_SIZE_Y 10
#define INVENTORY_SIZE (9 * 10)

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
    dragndrop_t *display;
    int hp;
    int attack;
};
typedef struct item item_t;

struct inventory {
    item_t *stock[INVENTORY_SIZE_X * INVENTORY_SIZE_Y];
    item_t *stuff[3][6];
    item_t *item_dragging;
    int state;
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

// inventory_core.c
void inventory_compute(inventory_t *inv);
void inventory_draw(inventory_t *inv);
void inventory_event(inventory_t *inv);

static const sfVector2f stuff_grid[6] = {
{130, 100}, {210, 100},
{130, 190}, {210, 190},
{130, 270}, {210, 270}};

#endif /* !INVENTORY_H_ */
