/*
** EPITECH PROJECT, 2019
** test
** File description:
** proto
*/

#pragma once
#include "struct.h"

void event_management(wind_t *wind, controls_t *control);
void animation(sfIntRect *rect, int start, int offset, int max_value);
sfBool pp_intersect(const sfSprite *a, const sfSprite *b, const sfImage *imgA, const sfImage *imgB);
sfIntRect f_to_i_rect(sfFloatRect f);
void house_interaction(obj_t *obj, house_t **house);
house_t *create_house(int type, sfVector2f housePos);
void init_controls(controls_t *controls);
