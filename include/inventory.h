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

#define INVENTORY_SIZE_X 6
#define INVENTORY_SIZE_Y 6

enum items {
    WEAPON = 0,
    HELMET,
    ARMOR,
    PANTS,
    BOOTS,
    SHIELD
};

struct item_s {
    char *name;
    dragndrop_t *display;
    int armor;
    int attack;
    int hp;
};
typedef struct item_s item_t;

typedef struct inventory_s {
    sfRenderWindow *window;
    sfSprite *background;
    int should_display;
    item_t *items[INVENTORY_SIZE_Y][INVENTORY_SIZE_X];
    item_t *stuff[6];

} inventory_t;


// item
item_t *item_create(char *name, SFT *idle, SFT *dragged, SFT *img_drag);
void item_destroy(item_t *item);
void item_display(sfRenderWindow *window, item_t *item);
void item_event(item_t *item, sfRenderWindow *window);

// inventory
inventory_t *inventory_create(sfRenderWindow *window, sfTexture *background);
void inventory_destroy(inventory_t *inv);
void inventory_event(inventory_t *inv);
void inventory_draw(inventory_t *inv);

// inventory op.c
void inventory_add_item(inventory_t *inv, item_t *item);

//debug grid.c
void show_debug_grid(sfRenderWindow *window);

#endif /* !INVENTORY_H_ */
