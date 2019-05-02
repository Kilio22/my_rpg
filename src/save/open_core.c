/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** open_core
*/

#include "save.h"

void load(rpg_t *rpg, obj_t **objs)
{
    char *save_path = mg_strdup("saves/savex.ini");

    save_path[10] = '0' + rpg->game.nb_save;
    rpg->game.inv = inventory_create_from_file(rpg->wind.wind, save_path);
}