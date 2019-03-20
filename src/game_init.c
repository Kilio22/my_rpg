/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** game_init
*/

#include "rpg.h"

void init_game(rpg_t *rpg, obj_t **obj, house_t **house)
{
    init_save(obj, rpg);
    init_game_loop(rpg, obj, house);
}