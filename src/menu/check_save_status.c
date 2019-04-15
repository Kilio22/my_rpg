/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** check_save_status
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "rpg.h"

char *check_save_status(int save_nb)
{
    char *line = NULL;
    size_t size;
    FILE *stream = fopen(save_path[save_nb], "r");

    if (stream == NULL)
        return NULL;
    getline(&line, &size, stream);
    fclose(stream);
    return line;
}