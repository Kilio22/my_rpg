/*
** EPITECH PROJECT, 2019
** mygraphlib
** File description:
** dragndrop_accessor
*/

#include "my_dragndrop.h"

my_bool_t dragndrop_ispendingDrag(dragndrop_t *drag)
{
    if (drag->last_pos_released.x != -1)
        return (TRUE);
    return (FALSE);
}

sfVector2i dragndrop_getpendingDrag(dragndrop_t *drag)
{
    sfVector2i pos = {drag->last_pos_released.x, drag->last_pos_released.y};

    drag->last_pos_released = (sfVector2i){-1, -1};
    return (pos);
}