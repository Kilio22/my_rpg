/*
** EPITECH PROJECT, 2019
** inimy
** File description:
** ini_line
*/

#include "my_ini.h"

ini_line_t *ini_line_create(char *key)
{
    ini_line_t *line = malloc(sizeof(ini_line_t));

    line->key = mg_strdup(key);
    line->values = double_vector_create();
    return (line);
}

ini_line_t *ini_line_create_from_str(char *str)
{
    int size_key = 0;
    ini_line_t *line;
    char **values;

    while (str[size_key] != '[' && str[size_key] != '\0')
        size_key++;
    if (str[size_key] == '\0')
        return (NULL);
    line = ini_line_create(mg_strndup(str, size_key));
    if (mg_strlen(str) - size_key - 2 == 0)
        return (line);
    values = mg_strtok(mg_strndup(str + size_key + 1,
    mg_strlen(str) - size_key - 2), ";");
    size_key = 0;
    while (values[size_key]) {
        double_vector_push_back(line->values, mg_strdup(values[size_key]));
        size_key++;
    }
    mg_strtok_destroy(values);
    return (line);
}

void ini_line_destroy(ini_line_t *line)
{
    free(line->key);
    while (line->values->size) {
        free(line->values->start->content);
        double_vector_pop_top(line->values);
    }
    free(line->values);
    free(line);
}