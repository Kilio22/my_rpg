/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** simple_chain
*/

#include "my_chained.h"

simple_chained_t *simple_chain_create(void *content)
{
    simple_chained_t *link = malloc(sizeof(simple_chained_t));

    link->next = 0;
    link->content = content;
    return (link);
}

void simple_chain_push_back(simple_chained_t *link, void *content)
{
    simple_chained_t *new_link = simple_chain_create(content);

    while (link->next != 0)
        link = link->next;
    link->next = new_link;
}

void simple_chain_push_after(simple_chained_t *link, void *content)
{
    simple_chained_t *new = simple_chain_create(content);

    new->next = link->next;
    link->next = new;
}

void simple_chain_pop_after(simple_chained_t *link)
{
    simple_chained_t *to_remove = link->next;

    if (to_remove == 0)
        return;
    link->next = to_remove->next;
    free(to_remove);
}

void simple_chain_push_top(simple_chained_t **link, void *content)
{
    simple_chained_t *new = simple_chain_create(content);

    new->next = *link;
    *link = new;
}