/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** analyse_menu_mouse
*/

#include "rpg.h"

void analyse_menu_mouse_released(rpg_t *rpg, int key, obj_t **obj, house_t **h)
{
    if (key == 0) {
        MENU.buttons[MENU.highlight].status = 0;
        sfText_setColor(MENU.buttons[MENU.highlight].text, sfYellow);
        menu[MENU.highlight](rpg, obj, h);
    }
}

void analyse_menu_mouse_press(rpg_t *rpg, int key)
{
    if (key == 0 && check_mousepos_butt(rpg) != -1) {
        MENU.buttons[MENU.highlight].status = 1;
        sfText_setColor(MENU.buttons[MENU.highlight].text, sfBlue);
    }
}

void analyse_menu_mouse_move(rpg_t *rpg, int *move)
{
    WIND.mouse_pos.x = WIND.event.mouseMove.x;
    WIND.mouse_pos.y = WIND.event.mouseMove.y;
    check_button_hovered(rpg, move);
}