/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** inventory_debug
*/

#include "inventory.h"

void inventory_show_debug(inventory_t *inv)
{
    inventory_show_debug_stuff(inv);
    inventory_show_debug_stock(inv);
}

void inventory_show_debug_stuff(inventory_t *inv)
{
    my_putstr("stuff: \n");
    for (int i = 0; i < 6; i++) {
        if (inv->stuff[i] == NULL)
            my_putstr("NULL\n");
        else {
            my_putstr(inv->stuff[i]->name);
            my_putchar('\n');
        }
    }
}

void inventory_show_debug_stock(inventory_t *inv)
{
    my_putstr("stock:\n");
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        if (inv->stock[i] != NULL) {
            my_putstr(inv->stock[i]->name);
            my_putchar('\n');
        }
    }
}