/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** menu_event
*/

#include "rpg.h"

int check_mousepos_butt(rpg_t *rpg)
{
    sfFloatRect text_pos;
    sfFloatRect mouse_pos = {WIND.mouse_pos.x, WIND.mouse_pos.y, 1, 1};

    for (int i = 0; i < 6; i++) {
        text_pos = sfText_getGlobalBounds(MENU.buttons[i].text);
        if (sfFloatRect_intersects(&text_pos, &mouse_pos, NULL))
            return (i);
    }
    return (-1);
}

void check_button_hovered(rpg_t *rpg)
{
    int i = check_mousepos_butt(rpg);

    if (i == -1 || MENU.buttons[MENU.highlight].status == 1)
        return;
    sfText_setColor(MENU.buttons[MENU.highlight].text, sfRed);
    MENU.highlight = i;
    sfText_setColor(MENU.buttons[MENU.highlight].text, sfYellow);
}

void menu_event_management(rpg_t *rpg, obj_t **obj, house_t **house)
{
    if (WIND.event.type == sfEvtKeyPressed)
        analyse_menu_key_pressed(WIND.event.key.code, rpg);
    if (WIND.event.type == sfEvtKeyReleased)
        analyse_menu_key_released(WIND.event.key.code, rpg, obj, house);
    if (WIND.event.type == sfEvtMouseButtonPressed)
        analyse_menu_mouse_press(rpg, WIND.event.mouseButton.button);
    if (WIND.event.type == sfEvtMouseButtonReleased)
        analyse_menu_mouse_released(rpg, WIND.event.mouseButton.button, obj, house);
    if (WIND.event.type == sfEvtMouseMoved)
        analyse_menu_mouse_move(rpg);
    if (WIND.event.type == sfEvtClosed)
        sfRenderWindow_close(WIND.wind);
}