/*
** EPITECH PROJECT, 2018
** mg_str_to_line_arr
** File description:
** mg_str_to_line_arr
*/

#include "mg_str.h"

line_arr_t *mg_str_to_line_arr(char const *str)
{
    line_arr_t *arr = malloc(sizeof(line_arr_t));
    int size_read = 0;

    arr->nb_line = mg_count_line(str);
    arr->arr = malloc(sizeof(char *) * arr->nb_line);
    for (int i = 0; i < arr->nb_line; i++) {
        int size = mg_line_lenght(str + size_read);
        arr->arr[i] = mg_strndup(str + size_read, size);
        size_read += size + 1;
    }
    return (arr);
}

void destroy_line_arr(line_arr_t *arr)
{
    for (int i = 0; i < arr->nb_line; i++) {
        free(arr->arr[i]);
    }
    free(arr->arr);
    free(arr);
}