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
#include "my_ini.h"

char *check_save_status(int save_nb)
{
    char *save_path = mg_strdup("saves/savex.ini");
    ini_file_t *ini;
    ini_line_t *name;

    save_path[10] = '0' + save_nb;
    ini = ini_file_create_from_file(save_path);
    if (!ini)
        return (NULL);
    name = ini_file_get_from_key(ini, "NAME");
    if (!name)
        return (NULL);
    return (mg_strdup(ini_line_get_value_from_col(name, 0)));
}