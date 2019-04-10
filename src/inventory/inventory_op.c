/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** inventory_op
*/

#include "inventory.h"

static int found_empty_inv_case(inventory_t *inv)
{
    for (int i = 0; i < INVENTORY_SIZE_X * INVENTORY_SIZE_Y; i++) {
        if (inv->stock[i] == NULL)
            return (i);
    }
    return (-1);
}

my_bool_t inventory_add_item_to_stock(inventory_t *inv, item_t *item)
{
    int index = found_empty_inv_case(inv);

    if (index == -1)
        return (FALSE);
    inv->stock[index] = item;
    return (TRUE);
}

void inventory_remove_item_from_stock(inventory_t *inv, item_t *item)
{
    int i = 0;

    while (i < INVENTORY_SIZE) {
        if (inv->stock[i] == item) {
            inv->stock[i] = NULL;
            return;
        }
    }
}

void inventory_add_item_to_stuff(inventory_t *inv, item_t *item, int type)
{
    if (inv->stuff[type] != NULL)
        inventory_add_item_to_stock(inv, inv->stuff[type]);
    inv->stuff[type] = item;
}

void inventory_remove_item_from_stuff(inventory_t *inv, item_t *item, int type)
{
    if (inv->stuff[type] == NULL)
        return;
    inv->stuff[type] = NULL;
}