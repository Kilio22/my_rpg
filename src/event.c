/*
** EPITECH PROJECT, 2018
** evetn
** File description:
** manage event
*/
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "my.h"
#include "struct.h"

void mouse_wheel_management(wind_t *wind, controls_t *control)
{
    if (wind->event.mouseWheel.delta == 1)
        control->bools[ZOOM] = 1;
    else if (wind->event.mouseWheel.delta == -1)
        control->bools[DEZOOM] = 1;
}

void manage_key_pressed(wind_t *wind, controls_t *control)
{
    if (wind->event.key.code == control->keys[UP])
        control->bools[KEYUP] = 1;
    if (wind->event.key.code == control->keys[DOWN])
        control->bools[KEYDOWN] = 1;
    if (wind->event.key.code == control->keys[LEFT])
        control->bools[KEYLEFT] = 1;
    if (wind->event.key.code == control->keys[RIGHT])
        control->bools[KEYRIGHT] = 1;
    //if (wind->event.key.code == control->keys[STATS])
    //    my_putstr("yes\n");
    if (wind->event.key.code == control->keys[INTERACT])
        control->bools[KEYINTER] = 1;
    if (wind->event.key.code == sfKeySpace)
        control->bools[KEYSPACE] = 1;
    if (wind->event.key.code == sfKeyY) {
        if (control->bools[KEYY] == 0)
            control->bools[KEYY] = 1;
        else
            control->bools[KEYY] = 0;
    }
    if (wind->event.key.code == sfKeyEscape)
        sfRenderWindow_close(wind->wind);
}

void manage_key_released(wind_t *wind, controls_t *control)
{
    if (wind->event.key.code == control->keys[UP])
        control->bools[KEYUP] = 0;
    if (wind->event.key.code == control->keys[DOWN])
        control->bools[KEYDOWN] = 0;
    if (wind->event.key.code == control->keys[LEFT])
        control->bools[KEYLEFT] = 0;
    if (wind->event.key.code == control->keys[RIGHT])
        control->bools[KEYRIGHT] = 0;
    if (wind->event.key.code == control->keys[INTERACT])
        control->bools[KEYINTER] = 0;
    if (wind->event.key.code == sfKeySpace)
        control->bools[KEYSPACE] = 0;
}

void event_management(wind_t *wind, controls_t *control)
{
    if (wind->event.type == sfEvtMouseWheelMoved)
        mouse_wheel_management(wind, control);
    if (wind->event.type == sfEvtMouseMoved) {
        control->mousePos.x = wind->event.mouseMove.x;
        control->mousePos.y = wind->event.mouseMove.y;
    }
    if (wind->event.type == sfEvtKeyPressed)
        manage_key_pressed(wind, control);
    if (wind->event.type == sfEvtKeyReleased)
        manage_key_released(wind, control);
    if (wind->event.type == sfEvtClosed)
        sfRenderWindow_close(wind->wind);
}