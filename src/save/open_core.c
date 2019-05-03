/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** open_core
*/

#include "save.h"

static void restore_killed(rpg_t *rpg, ini_file_t *file)
{
    
}

void load(rpg_t *rpg, obj_t **objs)
{
    char *save_path = mg_strdup("saves/savex.ini");
    ini_file_t *file;

    save_path[10] = '0' + rpg->game.nb_save;
    rpg->game.inv = inventory_create_from_file(rpg->wind.wind, save_path);
    file = ini_file_create_from_file(save_path);
    restore_killed(rpg, file);
}