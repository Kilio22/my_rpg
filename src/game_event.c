/*
** EPITECH PROJECT, 2018
** evetn
** File description:
** manage event
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "rpg.h"

static void mouse_wheel_management(rpg_t *rpg)
{
    if (WIND.event.mouseWheel.delta == 1)
        CONTROLS.bools[ZOOM] = 1;
    else if (WIND.event.mouseWheel.delta == -1)
        CONTROLS.bools[DEZOOM] = 1;
}

void event_management(rpg_t *rpg)
{
    if (WIND.event.type == sfEvtMouseWheelMoved)
        mouse_wheel_management(rpg);
    if (WIND.event.type == sfEvtMouseMoved) {
        CONTROLS.mousePos.x = WIND.event.mouseMove.x;
        CONTROLS.mousePos.y = WIND.event.mouseMove.y;
    }
    if (WIND.event.type == sfEvtKeyPressed)
        manage_key_pressed(rpg);
    if (WIND.event.type == sfEvtKeyReleased)
        manage_key_released(rpg);
    if (WIND.event.type == sfEvtClosed)
        sfRenderWindow_close(WIND.wind);
}