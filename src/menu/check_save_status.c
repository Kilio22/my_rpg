/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** check_save_status
*/
#ifdef _WIN32
    #define _CRT_SECURE_NO_WARNINGS
#endif
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "rpg.h"

char *check_save_status(int save_nb, rpg_t *rpg)
{
    char *line = NULL;
    size_t size;
    FILE *stream = fopen(save_path[save_nb], "r");

    if (stream == NULL)
        return NULL;
    getline(&line, &size, stream);
    fclose(stream);
    if (GAME.language == 0)
        line = my_realloc_str("Nom : ", line);
    else
        line = my_realloc_str("Name : ", line);
    return line;
}