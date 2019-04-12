/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** main
*/

#include "inventory.h"
#include "my_ini.h"

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
    ini_file_t *file = ini_file_create_from_file("assets_data.ini");
    inventory_t *inv = inventory_create(init_window());
    item_t *item = item_create(0, file);
    item_t *item2 = item_create(1, file);

    inventory_add_item_to_stock(inv, item);
    inventory_add_item_to_stock(inv, item2);
    while (sfRenderWindow_isOpen(inv->window)) {
        sfEvent event;
        while (sfRenderWindow_pollEvent(inv->window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(inv->window);
        }
        sfRenderWindow_clear(inv->window, sfBlack);
        inventory_compute(inv);
        sfRenderWindow_display(inv->window);
    }
}