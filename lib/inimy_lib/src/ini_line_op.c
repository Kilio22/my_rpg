/*
** EPITECH PROJECT, 2019
** inimy
** File description:
** ini_line_op
*/

#include "my_ini.h"

int ini_line_getcol_nb(ini_line_t *entity)
{
    return (entity->value->size);
}

char *ini_line_getstr_from_col(ini_line_t *entity, int col)
{
    double_chained_t *current = entity->value->start;

    if (current == 0 || col > ini_line_getcol_nb(entity))
        return (NULL);
    for (int i = 0; i < col; i++)
        current = current->next;
    return ((char*)current->content);
}

double_chained_t *ini_line_getchain_from_col(ini_line_t *entity, int col)
{
    double_chained_t *current = entity->value->start;

    if (current == 0 || col > ini_line_getcol_nb(entity))
        return (NULL);
    for (int i = 0; i < col; i++)
        current = current->next;
    return (current);
}

void ini_line_remove_value(ini_line_t *entity, int col)
{
    double_chained_t *current = entity->value->start;

    if (ini_line_getcol_nb(entity) < col)
        return;
    for (int i = 0; i < col; i++)
        current = current->next;
    double_chain_pop_me(current);
}
