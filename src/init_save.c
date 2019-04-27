/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** controls
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "rpg.h"

int init_controls(rpg_t *rpg)
{
    CONTROLS.keys = malloc(sizeof(int) * 7);
    if (CONTROLS.keys == NULL) {
        return -1;
    }
    CONTROLS.keys[UP] = sfKeyZ;
    CONTROLS.keys[LEFT] = sfKeyQ;
    CONTROLS.keys[DOWN] = sfKeyS;
    CONTROLS.keys[RIGHT] = sfKeyD;
    CONTROLS.keys[INTERACT] = sfKeyE;
    CONTROLS.keys[INV] = sfKeyI;
    return 0;
}

int init_stats(obj_t **obj)
{
    for (int i = 0; i < 9; i++) {
        if (i == 4 || i == 5)
            continue;
        obj[i]->stats[LEVEL] = 1;
        obj[i]->stats[XP] = 0;
        obj[i]->stats[HPS] = 100;
        obj[i]->stats[ATK] = 10;
        obj[i]->stats[DEF] = 10;
        obj[i]->stats[SPEED] = 10;
    }
    return 0;
}

int init_save(rpg_t *rpg)
{
    if (init_controls(rpg) == -1) {
        rpg->error_code = 84;
        return -1;
    }
    return 0;
}