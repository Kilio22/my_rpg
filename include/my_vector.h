/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_vector
*/

#ifndef MY_VECTOR_H_
#define MY_VECTOR_H_

#include "my_chained.h"

struct simple_vector {
    simple_chained_t *start;
    simple_chained_t *end;
    int size;
};
typedef struct simple_vector simple_vector_t;

simple_vector_t *simple_vector_create(void);
void simple_vector_push_top(simple_vector_t *vect, void *content);
void simple_vector_push_back(simple_vector_t *vect, void *content);
void simple_vector_pop_top(simple_vector_t *vect);
void simple_vector_pop_back(simple_vector_t *vect);

#endif /* !MY_VECTOR_H_ */
