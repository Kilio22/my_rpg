/*
** EPITECH PROJECT, 2019
** inimy
** File description:
** ini_line_conv
*/

#include "my_ini.h"

static int ini_line_str_len(ini_line_t *entity)
{
    int size = my_strlen(entity->key) + 1 + entity->value->size;
    double_chained_t *current = entity->value->start;

    while (current != 0) {
        size += my_strlen((char*)current->content);
        current = current->next;
    }
    return (size);
}

char *ini_line_to_str(ini_line_t *entity)
{
    int size = ini_line_str_len(entity);
    double_chained_t *current = entity->value->start;
    int size_write = my_strlen(entity->key);
    char *line;

    line = malloc(sizeof(char) * (size + 1));
    my_strcpy(line, entity->key);
    line[size_write] = '[';
    size_write++;
    while (current != 0) {
        my_strcpy(line + size_write, (char*)current->content);
        size_write += my_strlen((char*)current->content) + 1;
        line[size_write - 1] = ';';
        current = current->next;
    }
    line[size_write - 1] = ']';
    line[size_write] = '\0';
    return (line);
}