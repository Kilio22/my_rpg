/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** check_save_status
*/

#ifdef _WIN32
    #define _CRT_SECURE_NO_WARNINGS
#endif
#include <fcntl.h>
#include <stdio.h>
#include "rpg.h"

char *check_save_status(int save_nb, rpg_t *rpg)
{
    char *line;
    char *name;
    size_t size;
    FILE *stream = fopen(save_path[save_nb], "r");

    if (stream == NULL)
        return NULL;
    name = get_next_line(stream);
    line = get_next_line(stream);
    while (line != NULL) {
        free(line);
        line = get_next_line(stream);
    }
    fclose(stream);
    if (GAME.language == 0)
        name = my_realloc_str("Nom : ", name);
    else
        name = my_realloc_str("Name : ", name);
    return name;
}