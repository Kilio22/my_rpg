/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** my_simple_vector_basics
*/

#include "my_vector.h"

simple_vector_t *simple_vector_create(void)
{
    simple_vector_t *vect = malloc(sizeof(simple_vector_t));

    vect->size = 0;
    vect->start = 0;
    vect->end = 0;
    return (vect);
}

void simple_vector_push_top(simple_vector_t *vect, void *content)
{
    if (vect->size == 0) {
        vect->start = simple_chain_create(content);
        vect->end = vect->start;
    } else {
        simple_chain_push_top(&vect->start, content);
        if (vect->size == 1)
            vect->end = vect->start->next;
    }
    vect->size++;
}

void simple_vector_push_back(simple_vector_t *vect, void *content)
{
    if (vect->start == 0) {
        vect->start = simple_chain_create(content);
        vect->end = vect->start;
    } else {
        simple_chain_push_after(vect->end, content);
        vect->end = vect->end->next;
    }
    vect->size++;
}

void simple_vector_pop_top(simple_vector_t *vect)
{
    if (vect->start == vect->end) {
        free(vect->start);
        vect->start = 0;
        vect->end = 0;
        vect->size = 0;
    } else {
        simple_chained_t *second = vect->start->next;
        free(vect->start);
        vect->start = second;
        vect->size--;
    }
}

void simple_vector_pop_back(simple_vector_t *vect)
{
    if (vect->start == vect->end)
        simple_vector_pop_top(vect);
    else {
        simple_chained_t *current = vect->start;
        while (current->next->next != 0)
            current = current->next;
        simple_chain_pop_after(current);
        vect->end = current;
        vect->size--;
    }
}