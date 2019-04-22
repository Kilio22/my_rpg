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

//analyse_menu_key.c
void analyse_menu_key_pressed(int code, rpg_t *rpg, int *move);
void analyse_menu_key_released(int code, rpg_t *rpg, obj_t **obj, house_t **h);

//analyse_menu_mouse.c
void analyse_menu_mouse_press(rpg_t *rpg, int key);
void analyse_menu_mouse_released(rpg_t *rpg, int key, obj_t **obj, house_t **h);
void analyse_menu_mouse_move(rpg_t *rpg, int *move);

//camera_gestion.c
void camera_control(rpg_t *rpg, sfVector2f pos, obj_t **obj);

//character_gestion.c
void follower(obj_t **obj, rpg_t *rpg);
void character_control(rpg_t *rpg, obj_t **obj, house_t **house);

//check_save_status.c
char *check_save_status(int save_nb);

//controls_events.c
int manage_control_events(rpg_t *rpg, int *high);

//controls_init.c
void init_controls_menu(rpg_t *rpg);
int check_mousepos_intersect(rpg_t *rpg, fields_t field[], int nb);

//create_house.c
house_t *create_house(int type, sfVector2f housePos);
void house_interaction(obj_t *obj, house_t **house, rpg_t *rpg);
int create_houses(house_t **house);

//create_obj.c
obj_t *create_object(const char *Path, sfVector2f pos, sfIntRect intrect,
sfBool centered);

//destroy_menu.c
void destroy_load(load_game_t *load);

//fill_map.c
void add_vector(sprite_t *sprites, sfVector2f pos, sprite_t **sprite);
void fill_sprite(sprite_t **oui, sfVector2f pos);
int create_sprite(sprite_t **sprites, char *path, int id, sfIntRect rect);

//free_save.c
void free_save(obj_t **obj, rpg_t *rpg);

//free.c
void free_map(map_t map);
void free_obj(obj_t *obj);
void free_array(char **array);
void free_house(house_t *house);
void free_objs(obj_t **obj);

//game_display.c
void game_loop(rpg_t *rpg, obj_t **obj, house_t **house);
void house_display(rpg_t *rpg, house_t **house);

//game_event.c
void event_management(rpg_t *rpg);
void manage_key_released(rpg_t *rpg);
void manage_key_pressed(rpg_t *rpg);

//game_init.c
int init_game(rpg_t *rpg, obj_t **obj, house_t **house);

//house_display.c
void check_house_display(obj_t *obj, house_t *house, rpg_t *rpg);
void exit_house(obj_t *obj, house_t *house, rpg_t *rpg);

//init.c
int init_save(rpg_t *rpg);

//intro_fcts1.c
void check_house_display_intro(obj_t **obj, house_t *house,
                                        rpg_t *rpg, int *opt);
int intro_control(obj_t **obj, int opt,rpg_t *rpg, house_t **house);
int intro_ennemi_ctrl(obj_t **obj, int opt, rpg_t *rpg, house_t **house);
int intro_ennemi_two(obj_t **obj, int opt, rpg_t *rpg, house_t **house);
int intro_port(obj_t **obj, int opt, rpg_t *rpg, house_t **house);
int intro_nathan(obj_t **obj, int opt, rpg_t *rpg, house_t **house);
int intro_nathan_echelle(obj_t **obj, int opt, rpg_t *rpg, house_t **house);
int intro_nathan_dialogue(obj_t **obj, int opt, rpg_t *rpg, house_t **house);
int intro_go_auberge(obj_t **obj, int opt, rpg_t *rpg, house_t **house);
int intro_go_auberge2(obj_t **obj, int opt, rpg_t *rpg, house_t **house);
int intro_go_auberge3(obj_t **obj, int opt, rpg_t *rpg, house_t **house);
int intro_go_auberge4(obj_t **obj, int opt, rpg_t *rpg, house_t **house);
int intro_go_auberge5(obj_t **obj, int opt, rpg_t *rpg, house_t **house);
int intro_go_auberge6(obj_t **obj, int opt, rpg_t *rpg, house_t **house);
int intro_go_auberge7(obj_t **obj, int opt, rpg_t *rpg, house_t **house);
int intro_go_auberge8(obj_t **obj, int opt, rpg_t *rpg, house_t **house);
int intro_go_auberge9(obj_t **obj, int opt, rpg_t *rpg, house_t **house);
int intro_go_auberge10(obj_t **obj, int opt, rpg_t *rpg, house_t **house);
int intro_go_auberge11(obj_t **obj, int opt, rpg_t *rpg, house_t **house);
int intro_go_auberge12(obj_t **obj, int opt, rpg_t *rpg, house_t **house);
int intro_go_auberge13(obj_t **obj, int opt, rpg_t *rpg, house_t **house);
int intro_go_auberge14(obj_t **obj, int opt, rpg_t *rpg, house_t **house);
int intro_go_auberge15(obj_t **obj, int opt, rpg_t *rpg, house_t **house);
int intro_go_auberge16(obj_t **obj, int opt, rpg_t *rpg, house_t **house);
int intro_go_auberge17(obj_t **obj, int opt, rpg_t *rpg, house_t **house);
int intro_go_auberge18(obj_t **obj, int opt, rpg_t *rpg, house_t **house);
int intro_go_auberge19(obj_t **obj, int opt, rpg_t *rpg, house_t **house);
int intro_go_auberge20(obj_t **obj, int opt, rpg_t *rpg, house_t **house);

//intro_event.c
void intro_event_management(rpg_t *rpg);
void update_fondu_rect(intro_t *intro, rpg_t *rpg);

//intro_text.c
int update_intro_text(rpg_t *rpg, size_t frames, intro_t *intro);
int intro_text_index(int *index, rpg_t *rpg, char **to_print, int *p_ind);
int clock_text_intro(int i);

//intro_move.c
void intro_action(rpg_t *rpg, obj_t **obj, house_t **house, intro_t *intro);

//load_game.c
void menu_load_game(rpg_t *rpg, obj_t **obj, house_t **house);
void init_text_load(load_game_t *new);
load_game_t init_load_game(void);
void update_rect_load(load_game_t *load, size_t frame);
void load_display(rpg_t *rpg, load_game_t *load);

//load_game_event.c
int check_load_game_events(rpg_t *rpg, load_game_t *load, obj_t **obj,
                                                        house_t **house);
int check_button_pressed_load(rpg_t *rpg, load_game_t *load, obj_t **obj,
                                                        house_t **house);
void check_move_load(rpg_t *rpg, load_game_t *load);
void check_mbutton_press_load(rpg_t *rpg, load_game_t *load, obj_t **obj,
                                                        house_t **house);
void update_time(sfTime *current_time, sfTime *old_time, rpg_t *rpg,
                                                        size_t *frames);

//layout_init.c
int map_init(rpg_t *rpg);

//list.c
simple_vector_t *init_list(int x, int y);
void modif_list(simple_vector_t *pos, obj_t *obj);

//map_init.c
int create_map(rpg_t *rpg);

//menu_display.c
void menu_loop(rpg_t *rpg, obj_t **obj, house_t **house);

//menu_event.c
void menu_event_management(rpg_t *rpg, obj_t **obj, house_t **house,
                                                    int *move_rect);
int check_mousepos_butt(rpg_t *rpg);
void check_button_hovered(rpg_t *rpg, int *move);

//menu_init.c
void init_menu(rpg_t *rpg, obj_t **obj, house_t **house);

//music.c
void set_music(rpg_t *rpg);
void create_music(rpg_t *rpg);
void set_volume(rpg_t *rpg, int high, settings_t *settings);

//menu_fcts.c
void menu_close_window(rpg_t *rpg, obj_t **obj, house_t **house);
void menu_new_game(rpg_t *rpg, obj_t **obj, house_t **house);
void menu_how_to_play(rpg_t *rpg, obj_t **obj, house_t **house);
void menu_credit(rpg_t *rpg, obj_t **obj, house_t **house);
sfRectangleShape *create_rect(sfVector2f pos, sfVector2f size);

//my_utils.c
int my_equal_len(char *str);
int layer_len(layer_t **layers);
int gid_len(first_gid_t **gid);
int my_tab_vector_len(sfVector2f **tab);
sfText *create_text(const char *font_fp, const char *str,
unsigned int size, sfVector2f pos);
char *my_ftoa(float value);

//new_game.c
void menu_new_game(rpg_t *rpg, obj_t **obj, house_t **house);
int check_new_game_events(rpg_t *rpg, load_game_t *load, obj_t **obj,
                                                        house_t **house);
int check_button_pressed_new(rpg_t *rpg, load_game_t *load, obj_t **obj,
                                                        house_t **house);
void check_mbutton_press_new(rpg_t *rpg, load_game_t *load, obj_t **obj,
                                                            house_t **house);

//new_game_event.c

//print_map.c
void print_map(sprite_t **sprites, obj_t **obj, wind_t wind);
void print_map2(sprite_t **sprites, obj_t **obj, wind_t wind);

//settings_init.c
settings_t init_settings(rpg_t *rpg);
void destroy_settings(settings_t *settings);

//settings_menu.c
int check_mousepos_butt_set(rpg_t *rpg, settings_t *settings);
void menu_settings(rpg_t *rpg, obj_t **obj, house_t **house);

//settings_events.c
int manage_settings_events(rpg_t *rpg, sfEvent event, settings_t *settings);

//settings_utils.c
int check_high_controls(int i);

//stats.c
void print_stats(obj_t **obj);

//time_gestion.c
int check_characters_clock(sfClock *clock, float limit);

//intro.c
int intro_game(rpg_t *rpg, obj_t **obj, house_t **house);
int game_create(rpg_t *rpg, obj_t **obj, house_t **house);

#endif /* !PROTO_H_ */