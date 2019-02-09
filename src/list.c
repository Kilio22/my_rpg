/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** list
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include "my_vector.h"
#include "my.h"
#include "pp_hitbox.h"
#include "proto.h"
#include "struct.h"

simple_vector_t *init_list(void)
{
    simple_vector_t *list = simple_vector_create();

    for (int x = -49; x < 0; x++) { //alloc
        sfVector2f *current = malloc(sizeof(sfVector2f));
        current->x = x;
        current->y = 0;
        simple_vector_push_back(list, current);
        x++;
    }
    return (list);
}

void modif_list(simple_vector_t *pos, obj_t *obj)
{
    sfVector2f *current = malloc(sizeof(sfVector2f));
    sfVector2f position = sfSprite_getPosition(obj->sprite);
    
    current->x = position.x;
    current->y = position.y;
    simple_vector_push_back(pos, current);
    free(pos->start->content);
    simple_vector_pop_top(pos);
}

//simple_vector_t *simple_vector_create(void); -> remplir
// pour ajouter a la fin de la liste (simple_vector_push_back)
// pour supprimer au debut de la liste (simple_vector_pop_top)

/*     
    -----------------------------------
    
    while (list->start != 0) { //free all
        free(list->start->content);
        simple_vector_pop_top(list);
    }

    ------------------------------------

    free(list->end->content); //remove last sfVector2f in list
    simple_vector_pop_back(list);
*/