/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** inventory
*/

#include "inventory.h"

static void inventory_load_assets(inventory_t *inv)
{
    sfTexture *a = sfTexture_createFromFile("assets/inventory/inv.png", NULL);
    sfTexture *b = sfTexture_createFromFile("assets/inventory/inv1.png", NULL);
    sfTexture *c = sfTexture_createFromFile("assets/inventory/inv2.png", NULL);
    sfTexture *d = sfTexture_createFromFile("assets/inventory/inv3.png", NULL);

    inv->grid = sfSprite_create();
    for (int i = 0; i < 3; i++)
        inv->inv_widget[i] = sfSprite_create();
    sfSprite_setTexture(inv->grid, a, sfTrue);
    sfSprite_setTexture(inv->inv_widget[0], b, sfTrue);
    sfSprite_setTexture(inv->inv_widget[1], c, sfTrue);
    sfSprite_setTexture(inv->inv_widget[2], d, sfTrue);
    for (int i = 0; i < 3; i++)
        sfSprite_setPosition(inv->inv_widget[i], (sfVector2f){40, 40});
    sfSprite_setPosition(inv->grid, (sfVector2f){450, 20});
}

inventory_t *inventory_create(sfRenderWindow *window)
{
    inventory_t *new = malloc(sizeof(inventory_t));

    if (new == NULL)
        return NULL;
    new->item_dragging = NULL;
    new->window = window;
    new->state = 0;
    new->should_exit = 0;
    for (int i = 0; i < INVENTORY_SIZE_X * INVENTORY_SIZE_Y; i++)
        new->stock[i] = NULL;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 6; j++)
            new->stuff[i][j] = NULL;
    }
    inventory_load_assets(new);
    return (new);
}

void inventory_destroy(inventory_t *inv)
{
    for (int i = 0; i < INVENTORY_SIZE_X * INVENTORY_SIZE_Y; i++) {
        if (inv->stock[i] != NULL)
            item_destroy(inv->stock[i]);
    }
    for (int i = 0; i < 6; i++) {
        if (inv->stock[6] != NULL)
            item_destroy(inv->stock[i]);
    }
    for (int i = 0; i < 3; i++) {
        sfTexture_destroy((sfTexture *)sfSprite_getTexture(inv->inv_widget[i]));
        sfSprite_destroy(inv->inv_widget[i]);
    }
    sfTexture_destroy((sfTexture *)sfSprite_getTexture(inv->grid));
    sfSprite_destroy(inv->grid);
}