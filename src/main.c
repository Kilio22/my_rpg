/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** main
*/

#include "inventory.h"

sfRenderWindow *init_window()
{
    sfVideoMode mode = {1280, 720, 32};
    sfRenderWindow *window;

    window = sfRenderWindow_create(mode, "debug", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return (window);
}

int main()
{
    sfRenderWindow *window = init_window();
    sfTexture *t = sfTexture_createFromFile("sword.png", NULL);
    item_t *item = item_create("test", t, t, t);
    inventory_t *inv = inventory_create(window, t);

    while (sfRenderWindow_isOpen(window)) {
        item_event(item, window);
        sfEvent event;
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_clear(window, sfBlack);
        show_debug_grid(window);
        inventory_draw(inv);
        sfRenderWindow_display(window);
    }
}