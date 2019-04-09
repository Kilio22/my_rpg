/*
** EPITECH PROJECT, 2019
** inimy
** File description:
** ini_file_get
*/

#include "my_ini.h"

ini_line_t *ini_file_get_from_key(ini_file_t *file, char *key)
{
    ini_line_t *current_content;
    double_chained_t *current = file->lines->start;

    while (current) {
        current_content = (ini_line_t *)current->content;
        if (my_strcmp(current_content->key, key))
            return (current_content);
        current = current->next;
    }
    return (NULL);
}