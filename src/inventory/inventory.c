/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** inventory
*/

#include "inventory.h"

inventory_t *inventory_create(sfRenderWindow *window, sfTexture *background)
{
    inventory_t *inv = malloc(sizeof(inventory_t));

    for (int i = 0; i < INVENTORY_SIZE_Y; i++) {
        for (int j = 0; j < INVENTORY_SIZE_X; j++)
            inv->items[i][j] = NULL;
    }
    inv->window = window;
    inv->background = sfSprite_create();
    inv->should_display = 0;
    sfSprite_setTexture(inv->background, background, sfTrue);
}

static destroy_inv_line(inventory_t *inv, int i)
{
    for (int j = 0; j < INVENTORY_SIZE_X; j++) {
        if (inv->items[i][j])
            free(inv->items[i][j]);
    }
}

void inventory_destroy(inventory_t *inv)
{
    sfSprite_destroy(inv->background);
    for (int i = 0; i < INVENTORY_SIZE_Y; i++)
        destroy_inv_line(inv, i);
    free(inv);
}