/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** inventory_event
*/

#include "inventory.h"

void inventory_event_stock(inventory_t *inv)
{
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        if (!inv->stock[i])
            continue;
        dragndrop_event(inv->stock[i]->display, inv->window);
    }
}

void inventory_event_stuff(inventory_t *inv)
{
    for (int i = 0; i < 6; i++) {
        if (!inv->stuff[inv->state][i])
            continue;
        dragndrop_event(inv->stuff[inv->state][i]->display, inv->window);
    }
}