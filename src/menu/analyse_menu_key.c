/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** analyse_menu_key
*/

#include "rpg.h"

void analyse_menu_key_released(int code, rpg_t *rpg, obj_t **obj, house_t **h)
{
    if (code == sfKeyReturn) {
        MENU.buttons[MENU.highlight].status = 0;
        sfText_setColor(MENU.buttons[MENU.highlight].text, sfYellow);
        menu[MENU.highlight](rpg, obj, h);
    }
}

static void analyse_menu_arrows(int code, rpg_t *rpg, int *move)
{
    if (code == sfKeyDown && MENU.highlight < 5) {
        sfText_setColor(MENU.buttons[MENU.highlight].text, sfRed);
        MENU.highlight++;
        sfText_setColor(MENU.buttons[MENU.highlight].text, sfYellow);
        *move = 1;
    }
    if (code == sfKeyUp && MENU.highlight > 0) {
        sfText_setColor(MENU.buttons[MENU.highlight].text, sfRed);
        MENU.highlight--;
        sfText_setColor(MENU.buttons[MENU.highlight].text, sfYellow);
        *move = 1;
    }
}

void analyse_menu_key_pressed(int code, rpg_t *rpg, int *move)
{
    if (code == sfKeyEscape)
        sfRenderWindow_close(WIND.wind);
    if (code == sfKeyF1)
        GAME.nb_save = 0;
    if (code == sfKeyF2)
        GAME.nb_save = 1;
    if (code == sfKeyF5)
        set_music(rpg);
    if (code == sfKeyReturn) {
        MENU.buttons[MENU.highlight].status = 1;
        sfText_setColor(MENU.buttons[MENU.highlight].text, sfBlue);
    }
    analyse_menu_arrows(code, rpg, move);
}