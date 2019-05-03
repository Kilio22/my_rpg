/*
** EPITECH PROJECT, 2019
** inimy
** File description:
** ini_file
*/

#include "my_ini.h"

ini_file_t *ini_file_create(void)
{
    ini_file_t *file = malloc(sizeof(ini_file_t));

    file->lines = double_vector_create();
    file->path = NULL;
    return (file);
}

ini_file_t *ini_file_create_from_str(char *str)
{
    ini_file_t *file = ini_file_create();
    char **arr = mg_strtok(str, "\n");
    ini_line_t *buff;
    int i = 0;

    while (arr[i]) {
        buff = ini_line_create_from_str(arr[i]);
        if (buff)
            double_vector_push_back(file->lines, buff);
        i++;
    }
    for (int i = 0; arr[i]; i++)
        free(arr[i]);
    free(arr);
    return (file);
}

ini_file_t *ini_file_create_from_file(char *path, int nb)
{
    char *buff = my_file_readall(path, nb);
    ini_file_t *file;

    if (buff == NULL)
        return (NULL);
    file = ini_file_create_from_str(buff);
    file->path = mg_strdup(path);
    return (file);
}