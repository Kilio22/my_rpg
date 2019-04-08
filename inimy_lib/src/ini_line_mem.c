/*
** EPITECH PROJECT, 2019
** inimy
** File description:
** ini_line
*/

#include "my_ini.h"

static double_vector_t *get_values_from_line(char const *line)
{
    double_vector_t *vect = double_vector_create();
    int i = 0;
    int size = 0;

    while (line[i] != '[')
        i++;
    i++;
    if (line[i] == ']')
        return (vect);
    while (line[i-1] != ']') {
        while (line[i] != ']' && line[i] != ';') {
            i++;
            size++;
        }
        double_vector_push_back(vect, my_strndup(line + i - size, size));
        size = 0;
        i++;
    }
    return (vect);
}

ini_line_t *ini_line_create_from_str(char const *str)
{
    ini_line_t *new = malloc(sizeof(ini_line_t));
    int i = 0;

    while (str[i] != '[')
        i++;
    new->key = my_strndup(str, i);
    new->value = get_values_from_line(str);
    return (new);
}

ini_line_t *ini_line_create(char const *key)
{
    ini_line_t *new = malloc(sizeof(ini_line_t));

    new->key = my_strdup(key);
    new->value = double_vector_create();
    return (new);
}

void ini_line_destroy(ini_line_t *entity)
{
    while (entity->value->size != 0) {
        free(entity->value->start->content);
        double_vector_pop_top(entity->value);
    }
    free(entity->key);
    free(entity->value);
    free(entity);
}