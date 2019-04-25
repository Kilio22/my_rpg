/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** main
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdio.h>
#include "rpg.h"

int init_main(rpg_t *rpg)
{
    sfVector2u windowSize;

    rpg->wind.wind = create_window("Nuck Fathan", 10);
    windowSize = sfRenderWindow_getSize(rpg->wind.wind);
    rpg->wind.view =
sfView_createFromRect((sfFloatRect){0, 0, windowSize.x, windowSize.y});
    rpg->game.nb_save = 0;
    rpg->game.language = 0;
    rpg->controls.bools = malloc(sizeof(sfBool) * 10);
    if (rpg->controls.bools == NULL)
        return (84);
    for (int i = 0; i < 10; i++)
        rpg->controls.bools[i] = 0;
    rpg->error_code = 0;
    create_music(rpg);
    return 0;
}

int main(void)
{
    rpg_t rpg;
    obj_t **obj = malloc(sizeof(obj_t *) * 11);
    house_t **house = malloc(sizeof(house_t *) * (NB_HOUSE + 1));

    if (obj == NULL || house == NULL)
        return (84);
    if (create_houses(house) == -1)
        return 84;
    rpg.house = house;
    if (init_main(&rpg) == 84)
        return 84;
    srand((unsigned long) rpg.wind.wind);
    init_menu(&rpg, obj, house);
    if (rpg.error_code == 84)
        return (84);
    sfMusic_destroy(rpg.game.back_music);
    for (int i = 0; i < NB_HOUSE; i++)
        free_house(house[i]);
    return (0);
}

/*#include "inventory.h"
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
    return 0;
}*/