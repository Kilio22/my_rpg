/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** analyse_game_key
*/

#include "rpg.h"

void manage_other_key_pressed(rpg_t *rpg)
{
    if (WIND.event.key.code == CONTROLS.keys[INTERACT])
        CONTROLS.bools[KEYINTER] = 1;
    if (WIND.event.key.code == sfKeySpace)
        CONTROLS.bools[KEYSPACE] = 1;
    if (WIND.event.key.code == sfKeyY) {
        if (CONTROLS.bools[KEYY] == 0)
            CONTROLS.bools[KEYY] = 1;
        else
            CONTROLS.bools[KEYY] = 0;
    }
    if (WIND.event.key.code == sfKeyF5)
        set_music(rpg);
    if (WIND.event.key.code == sfKeyEscape)
        MENU.menu_on = 0;
}

void manage_key_pressed(rpg_t *rpg, obj_t **obj)
{
    if (WIND.event.key.code == CONTROLS.keys[UP])
        CONTROLS.bools[KEYUP] = 1;
    if (WIND.event.key.code == CONTROLS.keys[DOWN])
        CONTROLS.bools[KEYDOWN] = 1;
    if (WIND.event.key.code == CONTROLS.keys[LEFT])
        CONTROLS.bools[KEYLEFT] = 1;
    if (WIND.event.key.code == CONTROLS.keys[RIGHT])
        CONTROLS.bools[KEYRIGHT] = 1;
    if (WIND.event.key.code == CONTROLS.keys[STATS])
        print_stats(obj);
    manage_other_key_pressed(rpg);
}

void manage_key_released(rpg_t *rpg)
{
    if (WIND.event.key.code == CONTROLS.keys[UP])
        CONTROLS.bools[KEYUP] = 0;
    if (WIND.event.key.code == CONTROLS.keys[DOWN])
        CONTROLS.bools[KEYDOWN] = 0;
    if (WIND.event.key.code == CONTROLS.keys[LEFT])
        CONTROLS.bools[KEYLEFT] = 0;
    if (WIND.event.key.code == CONTROLS.keys[RIGHT])
        CONTROLS.bools[KEYRIGHT] = 0;
    if (WIND.event.key.code == sfKeySpace)
        CONTROLS.bools[KEYSPACE] = 0;
}