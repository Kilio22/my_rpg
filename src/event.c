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

void mouse_wheel_management(wind_t *wind, myBool_t *myBool)
{
    if (wind->event.mouseWheel.delta == 1)
        myBool->zoom = 1;
    else if (wind->event.mouseWheel.delta == -1)
        myBool->deZoom = 1;
}

void manage_key_pressed(wind_t *wind, myBool_t *myBool)
{
    if (wind->event.key.code == sfKeyZ || wind->event.key.code == sfKeyUp)
        myBool->keyUp = 1;
    if (wind->event.key.code == sfKeyS || wind->event.key.code == sfKeyDown)
        myBool->keyDown = 1;
    if (wind->event.key.code == sfKeyQ || wind->event.key.code == sfKeyLeft)
        myBool->keyLeft = 1;
    if (wind->event.key.code == sfKeyD || wind->event.key.code == sfKeyRight)
        myBool->keyRight = 1;
    if (wind->event.key.code == sfKeySpace)
        myBool->keySpace = 1;
    if (wind->event.key.code == sfKeyY) {
        if (myBool->keyY == 0)
            myBool->keyY = 1;
        else
            myBool->keyY = 0;
    }
    if (wind->event.key.code == sfKeyEscape)
        sfRenderWindow_close(wind->wind);
}

void manage_key_released(wind_t *wind, myBool_t *myBool)
{
    if (wind->event.key.code == sfKeyZ || wind->event.key.code == sfKeyUp)
        myBool->keyUp = 0;
    if (wind->event.key.code == sfKeyS || wind->event.key.code == sfKeyDown)
        myBool->keyDown = 0;
    if (wind->event.key.code == sfKeyQ || wind->event.key.code == sfKeyLeft)
        myBool->keyLeft = 0;
    if (wind->event.key.code == sfKeyD || wind->event.key.code == sfKeyRight)
        myBool->keyRight = 0;
    if (wind->event.key.code == sfKeySpace)
        myBool->keySpace = 0;
}

void event_management(wind_t *wind, myBool_t *myBool)
{
    if (wind->event.type == sfEvtMouseWheelMoved)
        mouse_wheel_management(wind, myBool);
    if (wind->event.type == sfEvtMouseMoved) {
        myBool->mousePos.x = wind->event.mouseMove.x;
        myBool->mousePos.y = wind->event.mouseMove.y;
    }
    if (wind->event.type == sfEvtKeyPressed)
        manage_key_pressed(wind, myBool);
    if (wind->event.type == sfEvtKeyReleased)
        manage_key_released(wind, myBool);
    if (wind->event.type == sfEvtClosed)
        sfRenderWindow_close(wind->wind);
}