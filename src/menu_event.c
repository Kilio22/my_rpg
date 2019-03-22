/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** menu_event
*/

#include "rpg.h"

void menu_event_management(rpg_t *rpg, obj_t **obj, house_t **house)
{
    if (WIND.event.type == sfEvtKeyPressed)
        analyse_menu_key(WIND.event.key.code, rpg, obj, house);
    if (WIND.event.type == sfEvtClosed)
        sfRenderWindow_close(WIND.wind);
    if (WIND.event.type == sfEvtMouseMoved) {
        WIND.mouse_pos.x = WIND.event.mouseMove.x;
        WIND.mouse_pos.y = WIND.event.mouseMove.y;
    }
    // if (WIND.event.type == sfEvtMouseButtonPressed)
    //     if (WIND.event.mouseButton.button == sfMouseLeft)
    //         WIND.click = 1;
}