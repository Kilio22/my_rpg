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

static void manage_key_pressed2(rpg_t *rpg)
{
    if (WIND.event.key.code == CONTROLS.keys[INTERACT])
        CONTROLS.bools[KEYINTER] = 1;
    if (WIND.event.key.code == sfKeySpace)
        CONTROLS.bools[KEYSPACE] = 1;
    if (WIND.event.key.code == sfKeyY) {
        if (CONTROLS.bools[KEYY] == 0)
            CONTROLS.bools[KEYY] = 1;
        else
            CONTROLS.bools[KEYY] = 0;
    }
    if (WIND.event.key.code == sfKeyEscape)
        MENU.menu_on = 0;
}

static void manage_key_pressed(rpg_t *rpg, obj_t **obj)
{
    if (WIND.event.key.code == CONTROLS.keys[UP])
        CONTROLS.bools[KEYUP] = 1;
    if (WIND.event.key.code == CONTROLS.keys[DOWN])
        CONTROLS.bools[KEYDOWN] = 1;
    if (WIND.event.key.code == CONTROLS.keys[LEFT])
        CONTROLS.bools[KEYLEFT] = 1;
    if (WIND.event.key.code == CONTROLS.keys[RIGHT])
        CONTROLS.bools[KEYRIGHT] = 1;
    if (WIND.event.key.code == CONTROLS.keys[STATS])
        print_stats(obj);
    manage_key_pressed2(rpg);
}

static void manage_key_released(rpg_t *rpg)
{
    if (WIND.event.key.code == CONTROLS.keys[UP])
        CONTROLS.bools[KEYUP] = 0;
    if (WIND.event.key.code == CONTROLS.keys[DOWN])
        CONTROLS.bools[KEYDOWN] = 0;
    if (WIND.event.key.code == CONTROLS.keys[LEFT])
        CONTROLS.bools[KEYLEFT] = 0;
    if (WIND.event.key.code == CONTROLS.keys[RIGHT])
        CONTROLS.bools[KEYRIGHT] = 0;
    if (WIND.event.key.code == sfKeySpace)
        CONTROLS.bools[KEYSPACE] = 0;
}

void event_management(rpg_t *rpg, obj_t **obj)
{
    if (WIND.event.type == sfEvtMouseWheelMoved)
        mouse_wheel_management(rpg);
    if (WIND.event.type == sfEvtMouseMoved) {
        CONTROLS.mousePos.x = WIND.event.mouseMove.x;
        CONTROLS.mousePos.y = WIND.event.mouseMove.y;
    }
    if (WIND.event.type == sfEvtKeyPressed)
        manage_key_pressed(rpg, obj);
    if (WIND.event.type == sfEvtKeyReleased)
        manage_key_released(rpg);
    if (WIND.event.type == sfEvtClosed)
        sfRenderWindow_close(WIND.wind);
}