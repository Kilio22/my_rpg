/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** inventory
*/

#include "inventory.h"

inventory_t *inventory_create(sfRenderWindow *window)
{
    inventory_t *new = malloc(sizeof(inventory_t));

    if (new == NULL)
        return NULL;
    new->item_dragging = NULL;
    new->window = window;
    new->item_pos = NOTHING;
    for (int i = 0; i < INVENTORY_SIZE_X * INVENTORY_SIZE_Y; i++)
        new->stock[i] = NULL;
    for (int i = 0; i < 6; i++)
        new->stuff[i] = NULL;
    return (new);
}

void inventory_destroy(inventory_t *inv)
{
    for (int i = 0; i < INVENTORY_SIZE_X * INVENTORY_SIZE_Y; i++) {
        if (inv->stock[i] != NULL)
            item_destroy(inv->stock[i]);
    }
    for (int i = 0; i < 6; i++) {
        if (inv->stock[6] != NULL)
            item_destroy(inv->stock[i]);
    }
}

