/*
** EPITECH PROJECT, 2019
** test
** File description:
** proto
*/

#include "struct.h"
#include "my_vector.h"

#ifndef PROTO_H_
#define PROTO_H_

//animation.c
void all_character_animation(obj_t **obj);
void update_all_rect(obj_t **obj, house_t **house);

//camera_gestion.c
void camera_control(rpg_t *rpg, sfVector2f pos);

//character_gestion.c
void follower(obj_t **obj, rpg_t *rpg);
void character_control(rpg_t *rpg, obj_t *obj, house_t **house);

//create_house.c
house_t *create_house(int type, sfVector2f housePos);
void house_interaction(obj_t *obj, house_t **house, rpg_t *rpg);

//create_obj.c
obj_t *create_object(char *Path, sfVector2f pos, sfIntRect intrect,
sfBool centered);

//free_save.c
void free_save(obj_t **obj, rpg_t *rpg);

//game_display.c
void init_game_loop(rpg_t *rpg, obj_t **obj, house_t **house);

//game_event.c
void event_management(rpg_t *rpg, obj_t **obj);

//game_init.c
void init_game(rpg_t *rpg, obj_t **obj, house_t **house);

//init.c
void init_save(obj_t **obj, rpg_t *rpg);

//list.c
simple_vector_t *init_list(int x);
void modif_list(simple_vector_t *pos, obj_t *obj);

//menu_display.c
void init_menu_loop(rpg_t *rpg, obj_t **obj, house_t **house);

//menu_event.c
void menu_event_management(rpg_t *rpg, obj_t **obj, house_t **house);

//menu_init.c
void init_menu(rpg_t *rpg, obj_t **obj, house_t **house);

//stats.c
void print_stats(obj_t **obj);

#endif /* !PROTO_H_ */