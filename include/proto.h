/*
** EPITECH PROJECT, 2019
** test
** File description:
** proto
*/

#pragma once
#include "struct.h"

void event_management(wind_t *wind, control_t *control);
void animation(sfIntRect *rect, int start, int offset, int max_value);
sfBool pp_intersect(const sfSprite *a, const sfSprite *b, const sfImage *imgA, const sfImage *imgB);
house_t *create_house(int type, sfVector2f housePos);