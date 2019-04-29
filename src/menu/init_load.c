/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** init_load
*/

#include "rpg.h"

void init_load(rpg_t *rpg)
{
    sfTexture *texture =
sfTexture_createFromFile(menu_path[1][GAME.language], NULL);
    MENU.menu_sprite[1] = sfSprite_create();
    sfSprite_setTexture(MENU.menu_sprite[1], texture, sfTrue);
}