/*
** EPITECH PROJECT, 2019
** test
** File description:
** proto
*/

#pragma once
#include "struct.h"
#include "my_vector.h"

sfBool pp_intersect(const sfSprite *a, const sfSprite *b, const sfImage *imgA, const sfImage *imgB);
sfIntRect f_to_i_rect(sfFloatRect f);
sfRenderWindow *create_window(char *title, float scale);
obj_t *create_object(char *Path, sfVector2f pos, sfIntRect intrect, sfBool centered);
house_t *create_house(int type, sfVector2f housePos);
void display(wind_t *wind, obj_t **obj, house_t **house);
void init_stats(obj_t *obj, int fd);
void init_controls(rpg_t *rpg, int fd);
void init_save(wind_t *wind, obj_t **obj, rpg_t *rpg);
void event_management(wind_t *wind, controls_t *control, obj_t **obj);
void animation(sfIntRect *rect, int start, int offset, int max_value);
void house_interaction(obj_t *obj, controls_t *control, house_t **house);
void all_character_animation(obj_t **obj);
void update_all_rect(obj_t **obj, house_t **house);
void camera_control(wind_t *wind, controls_t *control, sfVector2f pos);
simple_vector_t *init_list(int x);
void modif_list(simple_vector_t *pos, obj_t *obj);
void follower(obj_t **obj, wind_t *wind);
void character_control(controls_t *control, obj_t *obj, house_t **house);
void print_stats(obj_t **obj);