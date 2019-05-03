/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** save_core
*/

#include "save.h"

static void save_name(ini_file_t *ini, rpg_t *rpg)
{
    ini_line_t *line = ini_line_create("NAME");

    if (rpg->game.name_save) {
        double_vector_push_top(line->values, mg_strdup(rpg->game.name_save));
        double_vector_push_top(ini->lines, line);
    }
}

static void save_killed(ini_file_t *ini, rpg_t *rpg)
{
    ini_line_t *line = ini_line_create("KILLED");
    char *buff;

    for (int i = 0; i < 3; i++) {
        buff = mg_itoa(rpg->killed[i]);
        double_vector_push_back(line->values, buff);
    }
    double_vector_push_back(ini->lines, line);
}

void save(rpg_t *rpg, obj_t **objs)
{
    char *save_path = mg_strdup("saves/savex.ini");
    ini_file_t *ini;

    save_path[10] = '0' + rpg->game.nb_save;
    inventory_save(rpg->game.inv, save_path);
    ini = ini_file_create_from_file(save_path);
    save_name(ini, rpg);
    save_killed(ini, rpg);
    ini_file_write_path(ini, save_path);
}