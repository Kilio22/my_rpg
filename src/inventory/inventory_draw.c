/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** inventory_draw
*/

#include "inventory.h"

void inventory_draw_background(inventory_t *inv)
{
    sfRenderWindow_drawSprite(inv->window, inv->grid, NULL);
    sfRenderWindow_drawSprite(inv->window, inv->inv_widget[inv->state], NULL);
}

static void draw_item_case(sfRenderWindow *window, int x, int y)
{
    sfRectangleShape *shape = sfRectangleShape_create();

    sfRectangleShape_setFillColor(shape, sfRed);
    sfRectangleShape_setPosition(shape, (sfVector2f){x, y});
    sfRectangleShape_setSize(shape, (sfVector2f){50, 50});
    sfRenderWindow_drawRectangleShape(window, shape, NULL);
    sfRectangleShape_destroy(shape);
}

void inventory_draw_debug(inventory_t *inv)
{
    int x;
    int y;

    for (int i = 0; i < 6; i++)
        draw_item_case(inv->window, stuff_grid[i].x, stuff_grid[i].y);
    for (int i = 0; i < INVENTORY_SIZE_Y; i++) {
        for (int j = 0; j < INVENTORY_SIZE_X; j++) {
            x = 481 + j * (50 + 23);
            y = 50 + i * (50 + 23);
            draw_item_case(inv->window, x, y);
        }
    }
    mg_putstr("x: ");
    mg_putnbr(sfMouse_getPositionRenderWindow(inv->window).x);
    mg_putstr("  y:");
    mg_putnbr(sfMouse_getPositionRenderWindow(inv->window).y);
    mg_putstr("\n");
}

void inventory_draw_stock(inventory_t *inv)
{
    int x;
    int y;
    dragndrop_t *current;

    for (int i = 0; i < INVENTORY_SIZE; i++) {
        if (!inv->stock[i])
            continue;
        current = inv->stock[i]->display;
        x = i % INVENTORY_SIZE_X;
        y = i / INVENTORY_SIZE_X;
        current->pos = (sfVector2f){481 + x * 73, 50 + y * 73};
        window_draw_dragndrop(inv->window, current);
    }
}

void inventory_draw_stuff(inventory_t *inv)
{
    for (int i = 0; i < 6; i++) {
        if (!inv->stuff[inv->state][i])
            continue;
        inv->stuff[inv->state][i]->display->pos = stuff_grid[i];
        window_draw_dragndrop(inv->window,
inv->stuff[inv->state][i]->display);
    }
}