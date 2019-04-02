/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** inventory
*/

#ifndef INVENTORY_H_
#define INVENTORY_H_

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "my_vector.h"
#include "my_dragndrop.h"
#include <stdlib.h>
#include "macros.h"
#include "my_str.h"

enum items {
    WEAPON = 0,
    HELMET,
    ARMOR,
    PANTS,
    BOOTS,
    SHIELD
};

typedef struct item_s {
    char *name;
    dragndrop_t *display;
    int armor;
    int attack;
    int hp;
} item_t;

typedef struct inventory_s {
    sfRenderWindow *window;
    int should_display;
    double_vector_t *items; //contain item_t *

} inventory_t;


// item
item_t *item_create(char *name, SFT *idle, SFT *dragged, SFT *img_drag);
void item_destroy(item_t *item);
void item_display(sfRenderWindow *window, item_t *item);
void item_event(item_t *item, sfRenderWindow *window);

#endif /* !INVENTORY_H_ */
