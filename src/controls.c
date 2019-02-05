/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** controls
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "pp_hitbox.h"
#include "proto.h"
#include "struct.h"

void init_controls(controls_t *controls)
{
    controls->keys = malloc(sizeof(int) * 5);

    controls->keys[UP] = sfKeyT;
    controls->keys[LEFT] = sfKeyF;
    controls->keys[RIGHT] = sfKeyH;
    controls->keys[DOWN] = sfKeyG;
    controls->keys[INTERACT] = sfKeyE;
}