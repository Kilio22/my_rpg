/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** save_core
*/

#include "save.h"

void save(rpg_t *rpg, obj_t **objs)
{
    char *save_path = mg_strdup("saves/savex.ini");
    ini_file_t *ini;

    write(0, "ok\n", 3);
    save_path[10] = '0' + rpg->game.nb_save;
    inventory_save(rpg->game.inv, save_path);
    ini = ini_file_create_from_file(save_path);
}