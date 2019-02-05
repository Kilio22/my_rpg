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
        control->zoom = 1;
    else if (wind->event.mouseWheel.delta == -1)
        control->deZoom = 1;
}

void manage_key_pressed(wind_t *wind, controls_t *control)
{
    if (wind->event.key.code == control->keys[UP])
        control->keyUp = 1;
    if (wind->event.key.code == control->keys[DOWN])
        control->keyDown = 1;
    if (wind->event.key.code == control->keys[LEFT])
        control->keyLeft = 1;
    if (wind->event.key.code == control->keys[RIGHT])
        control->keyRight = 1;
    if (wind->event.key.code == sfKeySpace)
        control->keySpace = 1;
    if (wind->event.key.code == sfKeyY) {
        if (control->keyY == 0)
            control->keyY = 1;
        else
            control->keyY = 0;
    }
    if (wind->event.key.code == sfKeyEscape)
        sfRenderWindow_close(wind->wind);
}

void manage_key_released(wind_t *wind, controls_t *control)
{
    if (wind->event.key.code == control->keys[UP])
        control->keyUp = 0;
    if (wind->event.key.code == control->keys[DOWN])
        control->keyDown = 0;
    if (wind->event.key.code == control->keys[LEFT])
        control->keyLeft = 0;
    if (wind->event.key.code == control->keys[RIGHT])
        control->keyRight = 0;
    if (wind->event.key.code == sfKeySpace)
        control->keySpace = 0;
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