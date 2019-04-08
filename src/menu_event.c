/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** menu_event
*/

#include "rpg.h"

void menu_event_management(rpg_t *rpg)
{
    if (WIND.event.type == sfEvtKeyPressed)
        analyse_menu_key(WIND.event.key.code, rpg);
    if (WIND.event.type == sfEvtClosed)
        sfRenderWindow_close(WIND.wind);
    if (WIND.event.type == sfEvtMouseMoved) {
        WIND.mouse_pos.x = WIND.event.mouseMove.x;
        WIND.mouse_pos.y = WIND.event.mouseMove.y;
    }
}