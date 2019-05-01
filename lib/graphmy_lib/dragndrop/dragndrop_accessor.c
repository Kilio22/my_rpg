/*
** EPITECH PROJECT, 2019
** mygraphlib
** File description:
** dragndrop_accessor
*/

#include "my_dragndrop.h"

my_bool_t dragndrop_ispendingdrag(dragndrop_t *drag)
{
    if (drag->last_pos_released.x != -1)
        return (TRUE);
    return (FALSE);
}

sfVector2i dragndrop_getpendingdrag(dragndrop_t *drag)
{
    sfVector2i pos = {drag->last_pos_released.x, drag->last_pos_released.y};

    drag->last_pos_released = (sfVector2i){-1, -1};
    return (pos);
}

static sfVector2f get_scale(sfSprite *s, int width, int height)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(s);
    sfVector2f new;

    new.x = width / bounds.width;
    new.y = height / bounds.height;
    return (new);
}

void dragndrop_set_size(dragndrop_t *drag, int x, int y)
{
    drag->scale_bt = get_scale(drag->state_img[0], x, y);
    drag->scale_dragged = get_scale(drag->drag_img, x, y);
}