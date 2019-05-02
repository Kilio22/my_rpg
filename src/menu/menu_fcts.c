/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** menu_fcts
*/

#include "rpg.h"

sfRectangleShape *create_rect(sfVector2f pos, sfVector2f size)
{
    sfRectangleShape *new = sfRectangleShape_create();

    sfRectangleShape_setOutlineThickness(new, 6);
    sfRectangleShape_setSize(new, size);
    sfRectangleShape_setFillColor(new, sfTransparent);
    sfRectangleShape_setOutlineColor(new, sfRed);
    sfRectangleShape_setPosition(new, pos);
    return new;
}

void menu_close_window(rpg_t *rpg, obj_t **obj, house_t **house)
{
    (void) obj;
    (void) house;
    sfRenderWindow_close(WIND.wind);
}