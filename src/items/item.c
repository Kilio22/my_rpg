/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** item
*/

#include "inventory.h"

item_t *item_create(char *name, SFT *idle, SFT *dragged, SFT *img_drag)
{
    item_t *item = malloc(sizeof(item_t));

    item->display = dragndrop_create(idle, dragged, img_drag);
    item->name = my_strdup(name);
    item->armor = 0;
    item->attack = 0;
    item->hp = 0;
    return (item);
}

void item_destroy(item_t *item)
{
    dragndrop_destroy(item->display);
    free(item);
}

void item_display(sfRenderWindow *window, item_t *item)
{
    sfRenderWindow_drawDragndrop(window, item->display);
}

void item_event(item_t *item, sfRenderWindow *window)
{
    dragndrop_event(item->display, window);
}