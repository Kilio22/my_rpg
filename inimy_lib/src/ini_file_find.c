/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** ini_file_find
*/

#include "my_ini.h"

ini_line_t *ini_file_getline_by_key(ini_file_t *file, char const *key)
{
    double_chained_t *current = file->lines->start;
    ini_line_t *current_content;

    while (current) {
        current_content = (ini_line_t *)current->content;
        if (my_strcmp(current_content->key, key) == TRUE)
            return (current_content);
        current = current->next;
    }
    return (NULL);
}