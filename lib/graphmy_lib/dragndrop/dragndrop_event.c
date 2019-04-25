/*
** EPITECH PROJECT, 2019
** mygraphlib
** File description:
** dragndrop_event
*/

#include "my_dragndrop.h"

my_bool_t dragndrop_isClicked(dragndrop_t *drag, sfRenderWindow *window)
{
    if (dragndrop_isHover(drag, window)) {
        if (sfMouse_isButtonPressed(sfMouseLeft))
            return (TRUE);
    }
    return (FALSE);
}

my_bool_t dragndrop_isHover(dragndrop_t *drag, sfRenderWindow *window)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(window);
    sfFloatRect rect = sfSprite_getGlobalBounds(drag->state_img[0]);

    if (pos.x > rect.left && pos.x < rect.left + rect.width) {
        if (pos.y > rect.top && pos.y < rect.top + rect.height)
            return (TRUE);
    }
    return (FALSE);
}

my_bool_t dragndrop_isUnderDragging(dragndrop_t *drag)
{
    if (drag->state == DRAGGED)
        return (TRUE);
    return (FALSE);
}

void dragndrop_event(dragndrop_t *drag, sfRenderWindow *window)
{
    static dragndrop_t *current = NULL;

    if (current != NULL && drag != current)
        return;
    if (drag->state == IDLE_DRAG && dragndrop_isClicked(drag, window)) {
        current = drag;
        drag->state = DRAGGED;
    }
    if (drag->state == DRAGGED && !sfMouse_isButtonPressed(sfMouseLeft)) {
        current = NULL;
        drag->state = IDLE_DRAG;
        drag->last_pos_released = sfMouse_getPositionRenderWindow(window);
    }
}