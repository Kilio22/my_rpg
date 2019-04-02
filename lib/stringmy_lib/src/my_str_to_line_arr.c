/*
** EPITECH PROJECT, 2018
** my_str_to_line_arr
** File description:
** my_str_to_line_arr
*/

#include "my_str.h"

line_arr_t *my_str_to_line_arr(char const *str)
{
    line_arr_t *arr = malloc(sizeof(line_arr_t));
    int size_read = 0;

    arr->nb_line = my_count_line(str);
    arr->arr = malloc(sizeof(char *) * arr->nb_line);
    for (int i = 0; i < arr->nb_line; i++) {
        int size = my_line_lenght(str + size_read);
        arr->arr[i] = my_strndup(str + size_read, size);
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