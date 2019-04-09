/*
** EPITECH PROJECT, 2019
** inimy
** File description:
** ini_line_conversion
*/

#include "my_ini.h"

static char *convert_empty(ini_line_t *line)
{
    int size = my_strlen(line->key) + 2;
    char *buff = malloc(sizeof(char) * (size + 1));

    my_strcpy(buff, line->key);
    buff[size - 2] = '[';
    buff[size - 1] = ']';
    buff[size] = '\0';
    return (buff); 
}

static int ini_line_size(ini_line_t *line)
{
    int size = my_strlen(line->key) + 2;
    double_chained_t *current = line->values->start;

    size += line->values->size - 1;
    while (current) {
        size += my_strlen((char*)current->content);
        current = current->next;
    }
    size++;
    return (size);
}

static char *ini_line_non_empty_to_str(ini_line_t *line)
{
    int size = ini_line_size(line);
    char *buff = malloc(sizeof(char) * size);
    double_chained_t *current = line->values->start;

    my_strcpy(buff, line->key);
    size = my_strlen(line->key) + 1;
    buff[size - 1] = '[';
    while (current) {
        my_strcpy(buff + size, (char *)current->content);
        size += my_strlen((char *)current->content) + 1;
        buff[size - 1] = ';';
        current = current->next;
    }
    buff[size - 1] = ']';
    buff[size] = '\0';
    return (buff);
}

char *ini_line_to_str(ini_line_t *line)
{
    if (line->values->size == 0)
        return (convert_empty(line));
    return (ini_line_non_empty_to_str(line));
}