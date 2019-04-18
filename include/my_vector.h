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

struct double_vector {
    double_chained_t *start;
    double_chained_t *end;
    int size;
};
typedef struct double_vector double_vector_t;

double_vector_t *double_vector_create(void);
void double_vector_push_back(double_vector_t *vect, void *content);
void double_vector_push_top(double_vector_t *vect, void *content);
void double_vector_pop_me(double_vector_t *vect, double_chained_t *node);
void double_vector_pop_back(double_vector_t *vect);
void double_vector_pop_top(double_vector_t *vect);

#endif /* !MY_VECTOR_H_ */
