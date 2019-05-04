/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** check_obj_display
*/

#include "rpg.h"

static int loop_min(obj_t **obj, int display[12])
{
    int min = -1;

    for (int i = 0; i < 12; i++) {
        if (is_in_display(i, display) == 1)
            continue;
        if (min == -1 || obj[i]->pos.y < obj[min]->pos.y)
            min = i;
    }
    return min;
}

static void full_display_order(obj_t **obj, int display[12])
{
    int index = free_display(display);
    int min = -1;

    while (index != -1) {
        min = loop_min(obj, display);
        display[index] = min;
        index = free_display(display);
    }
}

static void full_display(obj_t **obj, int display[12])
{
    int index;

    for (int i = 0; i < 12; i++) {
        index = free_display(display);
        if (index == -1)
            return;
        if (obj[i] == NULL)
            display[index] = i;
    }
    index = free_display(display);
    if (index == -1)
        return;
    display[index] = 0;
    index = free_display(display);
    if (index == -1)
        return;
    display[index] = 4;
    full_display_order(obj, display);
}

void check_obj_display(obj_t **obj, rpg_t *rpg)
{
    int display[12];
    int index;

    for (int i = 0; i < 12; i++)
        display[i] = -1;
    full_display(obj, display);
    for (int i = 0; i < 12; i++) {
        index = display[i];
        if (index == 0 || index == 4 || index == -1)
            continue;
        if (obj[index] == NULL)
            continue;
        sfRenderWindow_drawSprite(WIND.wind, obj[display[i]]->sprite, NULL);
    }
}
