/*
** EPITECH PROJECT, 2019
** chainmy
** File description:
** double_vector_pop
*/

#include "my_vector.h"

void double_vector_pop_me(double_vector_t *vect, double_chained_t *node)
{
    if (vect->start == vect->end) {
        vect->size = 0;
        free(vect->start);
        vect->start = 0;
        vect->end = 0;
        return;
    }
    if (node == vect->start)
        vect->start = node->next;
    if (node == vect->end)
        vect->end = node->prev;
    double_chain_pop_me(node);
    vect->size--;
}

void double_vector_pop_back(double_vector_t *vect)
{
    double_vector_pop_me(vect, vect->end);
}

void double_vector_pop_top(double_vector_t *vect)
{
    double_vector_pop_me(vect, vect->start);
}