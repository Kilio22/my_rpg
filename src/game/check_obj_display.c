/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** check_obj_display
*/

#include "rpg.h"

static int free_display(int *display)
{
    for (int i = 0; i < 12; i++)
        if (display[i] == -1)
            return i;
    return -1;
}

static void full_display(obj_t **obj, int **display)
{
    int index;

    for (int i = 0; i < 12; i++) {
        index = free_display((*display));
        if (index == -1)
            return;
        if (obj[i] == NULL)
            (*display)[index] = i;
    }
    index = free_display((*display));
    if (index == -1)
        return;
    (*display)[index] = 0;
    index = free_display((*display));
    if (index == -1)
        return;
    (*display)[index] = 4;
}

void check_obj_display(obj_t **obj, rpg_t *rpg)
{
    int *display = malloc(sizeof(int) * 12);
    int index;

    for (int i = 0; i < 12; i++)
        display[i] = -1;
    full_display(obj, &display);
    for (int i = 0; i < 12; i++) {
        index = display[i];
        if (index == 0 || index == 4 || index == -1)
            continue;
        if (obj[index] == NULL)
            continue;
        sfRenderWindow_drawSprite(WIND.wind, obj[display[i]]->sprite, NULL);
    }
    free(display);
}
