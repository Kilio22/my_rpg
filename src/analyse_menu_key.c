/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** analyse_menu_key
*/

#include "rpg.h"

void analyse_menu_key(int code, rpg_t *rpg, obj_t **obj, house_t **house)
{
    if (code == sfKeyEscape)
        sfRenderWindow_close(WIND.wind);
    if (code == sfKeyF1)
        GAME.nb_save = 0;
    if (code == sfKeyF2)
        GAME.nb_save = 1;
    if (code == sfKeyF3)
        init_game(rpg, obj, house);
    // if (code == sfKeyF5)
    //     set_music(game);
}