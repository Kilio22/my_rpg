/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** double_chain
*/

#include "my_chained.h"

double_chained_t *double_chain_create(void *content)
{
    double_chained_t *link = malloc(sizeof(double_chained_t));

    link->content = content;
    link->prev = 0;
    link->next = 0;
    return (link);
}

void double_chain_push(double_chained_t *link, void *content)
{
    double_chained_t *current = link;
    double_chained_t *new = double_chain_create(content);

    while (current->next != 0)
        current = current->next;
    current->next = new;
    new->prev = current;
}
