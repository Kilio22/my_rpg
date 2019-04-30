/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** list
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "rpg.h"

simple_vector_t *init_list(int x, int y)
{
    simple_vector_t *list = simple_vector_create();
    int max = x + 50;

    for (; x < max; x++) {
        sfVector2f *current = malloc(sizeof(sfVector2f));
        if (current == NULL)
            return NULL;
        current->x = x;
        current->y = y;
        simple_vector_push_back(list, current);
        x++;
    }
    return (list);
}

void modif_list(simple_vector_t *pos, sfVector2f position)
{
    sfVector2f *current = malloc(sizeof(sfVector2f));

    if (current == NULL)
        return;
    current->x = position.x;
    current->y = position.y;
    simple_vector_push_back(pos, current);
    free(pos->start->content);
    simple_vector_pop_top(pos);
}
