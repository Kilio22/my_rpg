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

int main(int ac, char **av)
{
    rpg_t rpg;
    obj_t **obj = malloc(sizeof(obj_t *) * 10);
    house_t **house = malloc(sizeof(house_t *) * 6);
    sfVector2u windowSize;

    rpg.debug = 0;
    if (ac == 2) {
        if (my_strcmp(av[1], "-d") == 0)
            rpg.debug = 1;
        else
            return (84);
    }
    if (ac > 2)
        return 84;
    if (ac == 2 && my_strcmp(av[1], "-d") == 0)
        rpg.debug = 1;
    rpg.wind.wind = create_window("Nuck Fathan", 10);
    windowSize = sfRenderWindow_getSize(rpg.wind.wind);
    rpg.wind.view = sfView_createFromRect((sfFloatRect){0, 0, windowSize.x, windowSize.y});

    for (int i = 0; i < 10; i++)
        obj[i] = NULL;
    obj[0] = create_object("assets/hero_hitbox.png", (sfVector2f){10280, 2800}, (sfIntRect){0, 0, 32, 16}, sfTrue);
    obj[1] = create_object("assets/hero.png", (sfVector2f){10280, 2800}, (sfIntRect){0, 0, 32, 64}, sfFalse);
    obj[4] = create_object("assets/map_hitbox.png", (sfVector2f){0, 10}, (sfIntRect){0, 0, 11776, 2560}, sfFalse);
    obj[5] = create_object("assets/perso_blanc.png", (sfVector2f){10194, 1674}, (sfIntRect){0, 0, 32, 64}, sfTrue);
    obj[6] = create_object("assets/perso_blanc.png", (sfVector2f){10228, 1674}, (sfIntRect){0, 0, 32, 64}, sfTrue);
    obj[7] = create_object("assets/perso_blanc.png", (sfVector2f){10162, 1674}, (sfIntRect){0, 0, 32, 64}, sfTrue);
    house[0] = create_house(AUBERGE, (sfVector2f){9200, 768});
    house[1] = create_house(FORGE, (sfVector2f){9520, 864});
    house[2] = create_house(MAISON1, (sfVector2f){10944, 896});
    house[3] = create_house(MAISON2, (sfVector2f){9744, 960});
    house[4] = create_house(EGLISE, (sfVector2f){10272, 480});
    house[5] = NULL;

    sfSprite_setOrigin(obj[1]->sprite, (sfVector2f){16, 60});

    rpg.game.nb_save = 0;
    rpg.game.language = 0;
    rpg.controls.bools = malloc(sizeof(sfBool) * 9);
    for (int i = 0; i < 9; i++)
        rpg.controls.bools[i] = 0; 
    create_music(&rpg);
    init_menu(&rpg, obj, house);
    sfMusic_destroy(rpg.game.back_music);
    free_house(house);
    free_obj(obj);
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