/*
** EPITECH PROJECT, 2019
** test
** File description:
** proto
*/

#pragma once
#include "struct.h"

sfBool pp_intersect(const sfSprite *a, const sfSprite *b, const sfImage *imgA, const sfImage *imgB);
sfIntRect f_to_i_rect(sfFloatRect f);
sfRenderWindow *create_window(char *title, float scale);
obj_t *create_object(char *Path, sfVector2f pos, sfIntRect intrect, sfBool centered);
house_t *create_house(int type, sfVector2f housePos);
void display(wind_t *wind, obj_t **obj, house_t **house);
void init_controls(controls_t *controls);
void event_management(wind_t *wind, controls_t *control);
void animation(sfIntRect *rect, int start, int offset, int max_value);
void house_interaction(obj_t *obj, house_t **house);
void all_character_animation(obj_t **obj);
void update_all_rect(obj_t **obj);
void camera_control(wind_t *wind, controls_t *control, sfVector2f pos);
