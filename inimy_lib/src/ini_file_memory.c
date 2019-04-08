/*
** EPITECH PROJECT, 2019
** inimy
** File description:
** ini_file_memory
*/

#include "my_ini.h"

ini_file_t *ini_file_create(void )
{
    ini_file_t *new = malloc(sizeof(ini_file_t));

    new->path = 0;
    new->lines = double_vector_create();
    return (new);
}

ini_file_t *ini_file_create_from_str(char const *str)
{
    ini_file_t *new = ini_file_create();
    line_arr_t *arr = my_str_to_line_arr(str);

    for (int i = 0; i < arr->nb_line; i++) {
        if (arr->arr[i][0] == '\n')
            continue;
        ini_line_t *line = ini_line_create_from_str(arr->arr[i]);
        double_vector_push_back(new->lines, line);
    }
    destroy_line_arr(arr);
    return (new);
}

ini_file_t *ini_file_create_from_file(char const *path)
{
    char *str = my_file_readall(path);
    ini_file_t *new;

    if (str == 0) {
        free(str);
        return (0);
    }
    new = ini_file_create_from_str(str);
    new->path = my_strdup(path);
    free(str);
    return (new);
}

void ini_file_destroy(ini_file_t *file)
{
    double_chained_t *current = file->lines->start;
    ini_line_t *current_content = (ini_line_t *)current->content;

    while (current) {
        ini_line_destroy(current_content);
        double_vector_pop_top(file->lines);
        current = current->content;
        current_content = current->content;
    }
    free(file->lines);
    if (file->path != 0)
        free(file->path);
    free(file);
}