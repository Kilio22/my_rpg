/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** inventory_event
*/

#include "inventory.h"

void inventory_event_stock(inventory_t *inv)
{
    inventory_event_select(inv);
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

void inventory_event_select(inventory_t *inv)
{
    sfVector2i p = sfMouse_getPositionRenderWindow(inv->window);

    if (!sfMouse_isButtonPressed(sfMouseLeft))
        return;
    if (p.x > 285 && p.x < 360 && p.y > 200 && p.y < 261)
        inv->state = 0;
    if (p.x > 286 && p.x < 360 && p.y > 295 && p.y < 360)
        inv->state = 1;
    if (p.x > 286 && p.x < 360 && p.y > 360 && p.y < 415)
        inv->state = 2;
}