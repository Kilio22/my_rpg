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

void double_chain_push_back(double_chained_t *link, void *content)
{
    double_chained_t *current = link;
    double_chained_t *new = double_chain_create(content);

    while (current->next != 0)
        current = current->next;
    current->next = new;
    new->prev = current;
}

void double_chain_push_top(double_chained_t **link, void *content)
{
    double_chained_t *node = *link;

    while (node->prev != 0)
        node = node->prev;
    double_chain_push_before(node, content);
    *link = node->prev;
}

void double_chain_push_after(double_chained_t *link, void *content)
{
    double_chained_t *new = double_chain_create(content);

    if (link->next != 0)
        link->next->prev = new;
    new->prev = link;
    new->next = link->next;
    link->next = new;
}

void double_chain_push_before(double_chained_t *link, void *content)
{
    double_chained_t *new = double_chain_create(content);

    if (link->prev != 0)
        link->prev->next = new;
    new->prev = link->prev;
    new->next = link;
    link->prev = new;
}