/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** inventory_data
*/

#include "inventory.h"

int inventory_get_empty_case(inventory_t *inv)
{
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        if (inv->stock[i] == NULL)
            return (i);
    }
    return (-1);
}

void inventory_add_item(inventory_t *inv, item_t *item)
{
    int id = inventory_get_empty_case(inv);

    if (id == -1)
        return;
    inv->stock[id] = item;
}