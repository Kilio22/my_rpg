/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** inventory_core
*/

#include "inventory.h"

void inventory_draw(inventory_t *inv)
{
    inventory_draw_background(inv);
    inventory_draw_stock(inv);
    inventory_draw_stuff(inv);
    inventory_draw_debug(inv);
}

void inventory_event(inventory_t *inv)
{
    inventory_event_stock(inv);
    inventory_event_stuff(inv);
    inventory_compute(inv);
}

void inventory_compute(inventory_t *inv)
{
    inventory_compute_stock_released(inv);
    inventory_compute_stuff_released(inv);
}

static void window_event(inventory_t *inv)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(inv->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(inv->window);
        if (event.type == sfEvtKeyReleased && event.key.code == sfKeyEscape)
            inv->should_exit = 1;
    }
}

void inventory_loop(inventory_t *inv)
{
    sfImage *img = sfRenderWindow_capture(inv->window);
    sfTexture *t = sfTexture_create(1280, 720);
    sfTexture_updateFromImage(t, img, 0, 0);
    sfSprite *s = sfSprite_create();
    sfSprite_setTexture(s, t, sfTrue);

    const sfView *view_backup = sfRenderWindow_getView(inv->window);
    const sfView *default_view = sfRenderWindow_getDefaultView(inv->window);
    
    sfRenderWindow_setView(inv->window, default_view);
    while (sfRenderWindow_isOpen(inv->window) && inv->should_exit == 0) {
        window_event(inv);
        inventory_event(inv);
        sfRenderWindow_clear(inv->window, sfBlack);
        sfRenderWindow_drawSprite(inv->window, s, NULL);
        inventory_draw(inv);
        sfRenderWindow_display(inv->window);
    }
    inv->should_exit = 0;
    sfRenderWindow_setView(inv->window, view_backup);
}