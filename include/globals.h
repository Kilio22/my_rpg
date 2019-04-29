/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** globals
*/

#ifndef GLOBALS_H_
#define GLOBALS_H_

extern const char *save_path[3];
extern const char *house_path[8];
extern const sfIntRect house_rects[8];
extern const sfIntRect door_rects[8];
extern const sfVector2f door_pos[8];
extern const char *menu_path[][2];
extern const char *menu_str[6];
extern const char *menu_desc[6];
extern const sfVector2f menu_pos[6];
extern void (* const menu[6])(rpg_t *, obj_t **, house_t **);
extern const char *settings_str[4];
extern const sfVector2f settings_pos[4];
extern const char *settings_fp[5];
extern const sfVector2f settings_spr_pos[5];
extern const char *key_str[];
extern const char *scrpits[];
extern int (* const intro[])(obj_t **, int, rpg_t *, house_t **);
extern const char *obj_path[];
extern const int fog_off[54][2];
extern const char *ennemi_text[][2];
extern const char *attaques_names[][5];
extern const int global_damages[6][2];
extern const char *dial[][3];
extern const char *welcome[];
extern const char *answers[][2];
extern const char menu_font[];
#endif /* !GLOBALS_H_ */
