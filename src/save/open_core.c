/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** open_core
*/

#include "save.h"

static void killed_init_default(rpg_t *rpg)
{
    for (int i = 0; i < 3; i++)
        rpg->killed[i] = 0;
}

static void restore_killed(rpg_t *rpg, ini_file_t *file)
{
    ini_line_t *line = ini_file_get_from_key(file, "KILLED");
    char *buff;

    if (!line || line->values->size != 3) {
        killed_init_default(rpg);
        return;
    }
    for (int i = 0; i < 3; i++) {
        buff = ini_line_get_value_from_col(line, i);
        if (!my_strcmp(buff, "0") && !my_strcmp(buff, "1")) {
            killed_init_default(rpg);
            return;
        }
        rpg->killed[i] = buff[0] - '0';
    }
}

void load(rpg_t *rpg, obj_t **objs)
{
    char *save_path = mg_strdup("saves/savex.ini");
    ini_file_t *file;

    save_path[10] = '0' + rpg->game.nb_save;
    rpg->game.inv = inventory_create_from_file(rpg->wind.wind, save_path);
    file = ini_file_create_from_file(save_path, 6);
    restore_killed(rpg, file);
}