/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** globals
*/

#ifndef GLOBALS_H_
#define GLOBALS_H_

extern const char *save_path[3];
extern const char *house_path[5];
extern const sfIntRect house_rects[5];
extern const sfIntRect door_rects[5];
extern const sfVector2f door_pos[5];
extern const char *menu_path[2];
extern const char *menu_str[6];
extern const char *menu_desc[6];
extern const sfVector2f menu_pos[6];
extern void (* const menu[6])(rpg_t *, obj_t **, house_t **);
extern const char *settings_str[4];
extern const sfVector2f settings_pos[4];
extern const char *settings_fp[5];
extern const sfVector2f settings_spr_pos[5];
extern const char *key_str[];
extern const script_t *scrpits[2];

#endif /* !GLOBALS_H_ */
