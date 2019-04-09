/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** analyse_menu_key
*/

#include "rpg.h"

void analyse_menu_key(int code, rpg_t *rpg)
{
    if (code == sfKeyEscape)
        sfRenderWindow_close(WIND.wind);
    if (code == sfKeyF1)
        GAME.nb_save = 0;
    if (code == sfKeyF2)
        GAME.nb_save = 1;
    if (code == sfKeyF3)
        MENU.launch_game = 1;
    if (code == sfKeyF5)
        set_music(rpg);
}