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

enum {
    UP = 0,
    LEFT,
    RIGHT,
    DOWN,
    INTERACT
};

void setup_controls(controls_t *controls)
{
    controls->keys = malloc(sizeof(int) * 5);

    controls->keys[UP] = sfKeyZ;
    controls->keys[LEFT] = sfKeyQ;
    controls->keys[RIGHT] = sfKeyD;
    controls->keys[DOWN] = sfKeyS;
    controls->keys[INTERACT] = sfKeyE;
}