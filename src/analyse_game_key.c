/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** analyse_game_key
*/

#include "rpg.h"

void res_bools(rpg_t *rpg)
{
    for (int i = 0; i < 10; i++)
        CONTROLS.bools[i] = 0;
}

void manage_other_key_pressed(rpg_t *rpg)
{
    if (WIND.event.key.code == CONTROLS.keys[INTERACT])
        CONTROLS.bools[KEYINTER] = 1;
    if (WIND.event.key.code == sfKeySpace)
        CONTROLS.bools[KEYSPACE] = 1;
    if (WIND.event.key.code == sfKeyY && rpg->debug == 1) {
        if (CONTROLS.bools[KEYY] == 0)
            CONTROLS.bools[KEYY] = 1;
        else
            CONTROLS.bools[KEYY] = 0;
    }
    if (WIND.event.key.code == sfKeyF5)
        set_music(rpg);
    if (WIND.event.key.code == sfKeyEscape) {
        pause_game(rpg);
        res_bools(rpg);
    }
    if (WIND.event.key.code == sfKeyF12)
        screenshot(rpg);
}

void manage_key_pressed(rpg_t *rpg)
{
    if (WIND.event.key.code == CONTROLS.keys[UP])
        CONTROLS.bools[KEYUP] = 1;
    if (WIND.event.key.code == CONTROLS.keys[DOWN])
        CONTROLS.bools[KEYDOWN] = 1;
    if (WIND.event.key.code == CONTROLS.keys[LEFT])
        CONTROLS.bools[KEYLEFT] = 1;
    if (WIND.event.key.code == CONTROLS.keys[RIGHT])
        CONTROLS.bools[KEYRIGHT] = 1;
    if (WIND.event.key.code == CONTROLS.keys[INV]) {
        inventory_loop(rpg->game.inv);
        res_bools(rpg);
    }
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
    if (WIND.event.key.code == CONTROLS.keys[INTERACT])
        CONTROLS.bools[KEYINTER] = 0;
    if (WIND.event.key.code == sfKeySpace)
        CONTROLS.bools[KEYSPACE] = 0;
}