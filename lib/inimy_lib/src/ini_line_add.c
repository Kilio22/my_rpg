/*
** EPITECH PROJECT, 2019
** inimy
** File description:
** ini_line_add
*/

#include "my_ini.h"

void ini_line_add_value_from_col(ini_line_t *entity, int col, char const *str)
{
    int to_insert = col - ini_line_getcol_nb(entity);
    double_chained_t *current;

    for (int i = 0; i < to_insert + 1; i++)
        ini_line_push_back_value(entity, my_strdup(""));
    current = ini_line_getchain_from_col(entity, col);
    current->content = my_strdup(str);
}

void ini_line_push_back_value(ini_line_t *entity, char const *str)
{
    double_vector_push_back(entity->value, my_strdup(str));
}