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

static void put_rect(sfRenderWindow *window, sfIntRect rect)
{
    sfRectangleShape *shape = sfRectangleShape_create();

    sfRectangleShape_setPosition(shape, (sfVector2f){rect.left, rect.top});
    sfRectangleShape_setSize(shape, (sfVector2f){rect.width, rect.height});
    sfRenderWindow_drawRectangleShape(window, shape, NULL);
    sfRectangleShape_destroy(shape);
}

void inventory_draw_debug_grid(inventory_t *inv)
{
    sfIntRect rect;

    rect.width = 50;
    rect.height = 50;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            rect.left = 432 + (70 * j);
            rect.top = 20 + (i * 70);
            put_rect(inv->window, rect);
        }
    }
    for (int i = 0; i < 6; i++) {
        rect.left = stuff_grid[i].x;
        rect.top = stuff_grid[i].y;
        put_rect(inv->window, rect);
    }
}