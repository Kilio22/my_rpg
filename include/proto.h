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
void camera_control(rpg_t *rpg, sfVector2f pos, obj_t **obj);

//character_gestion.c
void follower(obj_t **obj, rpg_t *rpg);
void character_control(rpg_t *rpg, obj_t *obj, house_t **house);

//create_house.c
house_t *create_house(int type, sfVector2f housePos);
void house_interaction(obj_t *obj, house_t **house, rpg_t *rpg);

//create_obj.c
obj_t *create_object(char *Path, sfVector2f pos, sfIntRect intrect,
sfBool centered);

//fill_map.c
void add_vector(sprite_t *oui, sfVector2f pos);
void fill_sprite(sprite_t **oui, sfVector2f pos);
void create_sprite(sprite_t **oui, char *path, int id, sfIntRect rect);

//free_save.c
void free_save(obj_t **obj, rpg_t *rpg);

//game_display.c
void game_loop(rpg_t *rpg, obj_t **obj, house_t **house);
void house_display(rpg_t *rpg, house_t **house);

//game_event.c
void event_management(rpg_t *rpg, obj_t **obj);
void manage_key_released(rpg_t *rpg);
void manage_key_pressed(rpg_t *rpg, obj_t **obj);

//game_init.c
void init_game(rpg_t *rpg, obj_t **obj, house_t **house);

//init.c
void init_save(obj_t **obj, rpg_t *rpg);

//layout_init.c
void map_init(rpg_t *rpg);

//list.c
simple_vector_t *init_list(int x, int y);
void modif_list(simple_vector_t *pos, obj_t *obj);

//map_init.c
void create_map(rpg_t *rpg);

//menu_display.c
void init_menu_loop(rpg_t *rpg, obj_t **obj, house_t **house);

//menu_event.c
void menu_event_management(rpg_t *rpg);
void analyse_menu_key(int code, rpg_t *rpg);

//menu_init.c
void init_menu(rpg_t *rpg, obj_t **obj, house_t **house);

//music.c
void set_music(rpg_t *rpg);
void create_music(rpg_t *rpg);

//my_utils.c
int my_equal_len(char *str);
int layer_len(layer_t **layers);
int gid_len(first_gid_t **gid);
int my_tab_vector_len(sfVector2f **tab);

//print_map.c
void print_map(sprite_t **sprites, obj_t **obj, wind_t wind);

//stats.c
void print_stats(obj_t **obj);

//time_gestion.c
int check_characters_clock(sfClock *clock, float limit);


#endif /* !PROTO_H_ */