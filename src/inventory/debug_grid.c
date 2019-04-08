/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** debug_grid
*/

#include "inventory.h"

static void put_rect(sfRenderWindow *window, sfIntRect rect)
{
    sfRectangleShape *shape = sfRectangleShape_create();

    sfRectangleShape_setFillColor(shape, sfWhite);
    sfRectangleShape_setPosition(shape, (sfVector2f){rect.left, rect.top});
    sfRectangleShape_setSize(shape, (sfVector2f){rect.width, rect.height});
    sfRenderWindow_drawRectangleShape(window, shape, NULL);
    free(shape);
}

void show_debug_grid(sfRenderWindow *window)
{
    sfIntRect rect;

    rect.width = 50;
    rect.height = 50;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            rect.left = 432 + (70 * j);
            rect.top = 20 + (i * 70);
            put_rect(window, rect);
        }
    }
}