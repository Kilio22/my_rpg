/*
** EPITECH PROJECT, 2019
** chainmy
** File description:
** double_vector
*/

#include "my_vector.h"

double_vector_t *double_vector_create(void)
{
    double_vector_t *new = malloc(sizeof(double_vector_t));

    new->size = 0;
    new->start = 0;
    new->end = 0;
    return (new);
}

void double_vector_push_back(double_vector_t *vect, void *content)
{
    double_chained_t *to_insert;

    if (vect->start == 0) {
        to_insert = double_chain_create(content);
        vect->size++;
        vect->start = to_insert;
        vect->end = to_insert;
        return;
    }
    double_chain_push_after(vect->end, content);
    vect->end = vect->end->next;
    vect->size++;
}

void double_vector_push_top(double_vector_t *vect, void *content)
{
    if (vect->start == 0) {
        double_vector_push_back(vect, content);
        return;
    }
    double_chain_push_before(vect->start, content);
    vect->start = vect->start->prev;
    vect->size++;
}