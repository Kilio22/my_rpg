/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** check_save_status
*/

#include <fcntl.h>
#include <stdio.h>
#include "windows.h"
#include "rpg.h"
#include "my_ini.h"

char *check_save_status(int save_nb)
{
    char *save_path = mg_strdup("saves/savex.ini");
    ini_file_t *ini;
    ini_line_t *name;
    char *oui = NULL;

    save_path[10] = '0' + save_nb;
    ini = ini_file_create_from_file(save_path, 6);
    if (!ini)
        return (NULL);
    name = ini_file_get_from_key(ini, "NAME");
    if (!name || name->values->size == 0)
        return (NULL);
    oui = mg_strdup(ini_line_get_value_from_col(name, 0));
    if (!oui)
        return NULL;
    return (oui);
}