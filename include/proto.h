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

//character_animation
int character_hitbox(obj_t **obj, rpg_t *rpg, house_t **house);

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
void add_vector(sprite_t *sprites, sfVector2f pos);
void fill_sprite(sprite_t **oui, sfVector2f pos);
int create_sprite(sprite_t **sprites, char *path, int id, sfIntRect rect);

//free.c
void free_map(map_t map);
void free_obj(obj_t *obj);
void free_array(char **array);
void free_house(house_t *house);
void free_objs(obj_t **obj);

//game_display.c
void game_loop(rpg_t *rpg, obj_t **obj, house_t **house);
void house_display(rpg_t *rpg, house_t **house);
void check_obj_display(obj_t **obj, rpg_t *rpg);

//game_event.c
void event_management(rpg_t *rpg, obj_t **obj);
void manage_key_released(rpg_t *rpg);
void manage_key_pressed(rpg_t *rpg, obj_t **obj);
void update_inventory_stats(rpg_t *rpg, obj_t **obj);

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
int intro_control(obj_t **obj, int opt, rpg_t *rpg, house_t **house);
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
void intro_event_management(rpg_t *rpg, obj_t **obj, house_t **house);
void update_fondu_rect(intro_t *intro, rpg_t *rpg);
void intro_fcts(rpg_t *rpg, obj_t **obj, house_t **house, intro_t *intros);

//intro_text.c
int update_intro_text(rpg_t *rpg, intro_t *intro);
int intro_text_index(int *index, rpg_t *rpg, char **to_print, int *p_ind);
int clock_text_intro(int i);

//intro_move.c
void intro_action(rpg_t *rpg, obj_t **obj, house_t **house, intro_t *intro);

//intro_animation.c
void all_character_animation_intro(rpg_t *rpg, obj_t **obj);

//load_game.c
void menu_load_game(rpg_t *rpg, obj_t **obj, house_t **house);
load_game_t init_load_game(rpg_t *rpg);
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
size_t update_time(size_t *frames);

//layout_init.c
int map_init(rpg_t *rpg);

//list.c
simple_vector_t *init_list(int x, int y);
void modif_list(simple_vector_t *pos, sfVector2f position);

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
void init_load(rpg_t *rpg);
void init_menu(rpg_t *rpg, obj_t **obj, house_t **house);

//music.c
void set_music(sfMusic *music);
void create_music(rpg_t *rpg);
void set_sound_volume(rpg_t *rpg);
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
sfSound *create_sound(char const *path);
int check_pnj_clock_move(void);
void destroy_sounds(rpg_t *rpg);

//new_game.c
void menu_new_game(rpg_t *rpg, obj_t **obj, house_t **house);
int check_new_game_events(rpg_t *rpg, load_game_t *load, obj_t **obj,
                                                        house_t **house);
void check_mbutton_press_new(rpg_t *rpg, load_game_t *load, obj_t **obj,
                                                            house_t **house);

//new_game_event.c

//print_map.c
void print_map(sprite_t **sprites, obj_t **obj, wind_t wind);
void print_map2(sprite_t **sprites, obj_t **obj, wind_t wind);


//obj_display
void check_obj_display(obj_t **obj, rpg_t *rpg);

//settings_init.c
settings_t init_settings(rpg_t *rpg);
void destroy_settings(settings_t *settings, rpg_t *rpg);

//settings_menu.c
int check_mousepos_butt_set(rpg_t *rpg, settings_t *settings);
void menu_settings(rpg_t *rpg, obj_t **obj, house_t **house);

//settings_events.c
int manage_settings_events(rpg_t *rpg, sfEvent event, settings_t *settings);

//settings_utils.c
int check_high_controls(int i);

//time_gestion.c
int clock_door(void);
int check_characters_clock(sfClock *clock, float limit);

//intro.c
int intro_game(rpg_t *rpg, obj_t **obj, house_t **house);
int game_create(rpg_t *rpg, obj_t **obj, house_t **house);
void mouse_wheel_management(rpg_t *rpg);
void reset_char(obj_t **obj, rpg_t *rpg, house_t **house);
void display_char(rpg_t *rpg, obj_t **obj);

//fight
int update_fight_text(fight_t *fight, int flag, rpg_t *rpg);
void fight_action(rpg_t *rpg, obj_t **obj, house_t **house, fight_t *fight);
int fight_event_management(rpg_t *rpg, fight_t *fight);
void fight(obj_t **obj, rpg_t *rpg, int i, house_t **house);
int fight_text_intro(int i);
void update_fondu_rect_fight(fight_t *fight, rpg_t *rpg, int flag);
void check_pnj_display(house_t **house, obj_t **obj, rpg_t *rpg);
void display(rpg_t *rpg, obj_t **obj, house_t **house);
void update_attacks_pos(fight_t *new, rpg_t *rpg, int i);
void delete_fight(fight_t *fight, obj_t **obj, rpg_t *rpg);
fight_t create_fight(int i, rpg_t *rpg, obj_t **obj);
float calc_dist(sfVector2f pos1, sfVector2f pos2);
int is_in_display(int index, int display[12]);
int free_display(int display[12]);
void fight_camera_control(rpg_t *rpg, sfVector2f pos, obj_t **obj);
void positioning_life_perso(fight_t *new, rpg_t *rpg);
void choose_fighter(obj_t **obj, fight_t *fight, rpg_t *rpg, int i);
void sorter(int (*tab)[4], int (*tab_speed)[4]);
void update_choices(fight_t *fight, int turn, rpg_t *rpg);
void attack_allies(obj_t **obj, fight_t *fight, int i, rpg_t *rpg);
void attack_ennemi(obj_t **obj, fight_t *fight);
void apply_attack(obj_t **obj, fight_t *fight, rpg_t *rpg, int turn);
void manage_fight_allies(obj_t **obj, fight_t *fight, rpg_t *rpg, int i);
void manage_fight_ennemis(obj_t **obj, fight_t *fight, rpg_t *rpg, int i);
void check_end_pos(fight_t *fight, obj_t **obj, house_t **house, rpg_t *rpg);

//move pnj
void move_pnjs(obj_t **obj, house_t **house);

//framebuffer
void display_framebuffer(rpg_t *rpg);
void create_framebuffer(rpg_t *rpg);
void draw_square_fog(framebuffer_t *framebuffer, sfVector2u position,
unsigned int line);
void draw_square_fire(framebuffer_t *framebuffer, sfVector2u position,
unsigned int line);

//dialogues
dialogue_t create_dialogue(rpg_t *rpg, int i);
int dial_event_management(rpg_t *rpg, dialogue_t *dialogue);
void dial_action(rpg_t *rpg, obj_t **obj,
house_t **house, dialogue_t *dialogue);
void aubergiste_dial(obj_t **obj, rpg_t *rpg, int i, house_t **house);
int update_dial_text(dialogue_t *dialogue);
void destroy_dialogue(dialogue_t *dialogue);

//stats
int init_stats(obj_t **obj);
int fight_turn(obj_t **obj, fight_t *fight, int i);

//pause
void pause_game(rpg_t *rpg);

//globals.c
typedef int (* const intro_pointer_t)(obj_t **, int, rpg_t *, house_t **);
typedef void (* const intro_menu_t)(rpg_t *, obj_t **, house_t **);

//screenshot.c
void screenshot(rpg_t *rpg);

//end game
void check_end_game(rpg_t *rpg, int flag);
void update_rect_end(end_game_t *end, int flag);
int end_game_event(rpg_t *rpg);
int update_end_text(end_game_t *end);
end_game_t init_end_game(rpg_t *rpg);

//credit_menu.c
void credit_display(rpg_t *rpg, credit_t *credit);
int check_credit_events(rpg_t *rpg, credit_t *credits);

//load
int check_files(char **env);

//stats
int compute_attack_stat(inventory_t *inv, int nb_char);
int compute_health_stat(inventory_t *inv, int nb_char);

#endif /* !PROTO_H_ */