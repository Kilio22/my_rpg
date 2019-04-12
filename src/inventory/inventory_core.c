/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** inventory_core
*/

#include "inventory.h"

void inventory_compute(inventory_t *inv)
{
    inventory_draw(inv);
    inventory_event(inv);
}

void inventory_draw(inventory_t *inv)
{
    inventory_draw_debug_grid(inv);
    inventory_draw_stock(inv);
    inventory_draw_stuff(inv);
}

void inventory_event(inventory_t *inv)
{
    inventory_event_stock(inv);
    inventory_event_stuff(inv);
}