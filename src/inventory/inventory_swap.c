/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** inventory_swap
*/

#include "inventory.h"

void inventory_swap_to_stuff(inventory_t *inv, item_t *item, int type)
{
    if (inv->stuff[type] != NULL) {
        inventory_add_item_to_stock(inv, inv->stuff[type]);
        inv->stuff[type] = NULL;
    }
    inventory_remove_item_from_stock(inv, item);
    inv->stuff[type] = item;
}

void inventory_swap_to_stock(inventory_t *inv, int type)
{
    item_t *item = inv->stuff[type];

    inv->stuff[type] = NULL;
    inventory_add_item_to_stock(inv, item);
}