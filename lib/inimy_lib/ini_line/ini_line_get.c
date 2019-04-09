/*
** EPITECH PROJECT, 2019
** inimy
** File description:
** ini_line_get
*/

#include "my_ini.h"

char *ini_line_get_value_from_col(ini_line_t *line, int col)
{
    double_chained_t *current = line->values->start;
    char *current_content;

    for (int i = 0; i < col; i++) {
        if (!current)
            return (NULL);
        current = current->next;
    }
    if (!current)
        return (NULL);
    current_content = (char *)current->content;
    return (current_content);
}