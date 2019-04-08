/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** menu_init
*/

#include "rpg.h"

void init_menu(rpg_t *rpg, obj_t **obj, house_t **house)
{
    sfTexture *loading_texture =
sfTexture_createFromFile("assets/load.png", NULL);

    MENU.loading_screen = sfSprite_create();
    MENU.launch_game = 0;
    rpg->menu.menu_on = 1;
    sfSprite_setTexture(MENU.loading_screen, loading_texture, sfTrue);
    sfSprite_setPosition(MENU.loading_screen, V2F(0, 0));
    init_menu_loop(rpg, obj, house);
}