/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** inventory_common
*/

#include "inventory.h"

int is_collided_mouse_rect(sfIntRect rect, sfRenderWindow *window)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    if (mouse.x > rect.left && mouse.x < rect.left + rect.width) {
        if (mouse.y > rect.top && mouse.y < rect.top + rect.height)
            return (1);
    }
    return (0);
}

int inventory_get_id_from_coord(sfRenderWindow *window)
{
    sfIntRect rect;

    rect.height = 50;
    rect.width = 50;
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        rect.left = 477 + i % INVENTORY_SIZE_X * 73;
        rect.top = 46 + i / INVENTORY_SIZE_X * 73;
        if (is_collided_mouse_rect(rect, window))
            return (i);
    }
    return (-1);
}

int inventory_get_stuff_id_from_mouse(sfRenderWindow *window)
{
    sfIntRect rect;

    rect.width = 50;
    rect.height = 50;
    for (int i = 0; i < 6; i++) {
        rect.left = stuff_grid[i].x;
        rect.top = stuff_grid[i].y;
        if (is_collided_mouse_rect(rect, window))
            return (i);
    }
    return (-1);
}