/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** inventory_compute
*/

#include "inventory.h"

void do_op_stock_to_stuff(item_t *item, inventory_t *inv, int from)
{
    int id = inventory_get_stuff_id_from_mouse(inv->window);

    if (id == -1)
        return;
    if (inv->stuff[inv->state][id] != NULL || item->type != id)
        return;
    inv->stuff[inv->state][id] = item;
    inv->stock[from] = NULL;
}

static void do_dop_stock(item_t *item, inventory_t *inv, int from)
{
    int id = inventory_get_id_from_coord(inv->window);

    dragndrop_getpendingDrag(item->display);
    if (id == -1) {
        do_op_stock_to_stuff(item, inv, from);
        return;
    }
    if (inv->stock[id] != NULL)
        return;
    inv->stock[id] = item;
    inv->stock[from] = NULL;
}

void inventory_compute_stock_released(inventory_t *inv)
{
    dragndrop_t *current;

    for (int i = 0; i < INVENTORY_SIZE; i++) {
        if (!inv->stock[i])
            continue;
        current = inv->stock[i]->display;
        if (!dragndrop_ispendingDrag(current))
            continue;
        do_dop_stock(inv->stock[i], inv, i);
    }
}