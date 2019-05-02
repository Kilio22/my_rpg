/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** macros
*/

#ifndef MACROS_H_
#define MACROS_H_

#include "rpg.h"

#define V2F(x, y) (sfVector2f){x, y}
#define V2I(x, y) (sfVector2i){x, y}
#define V2U(x, y) (sfVector2u){x, y}
#define SFT sfTexture
#define GAME rpg->game
#define CONTROLS rpg->controls
#define WIND rpg->wind
#define MENU rpg->menu
#define MAP rpg->map
#define RECT_LEFT 32 * \
((layers->map[y][x] - MAP.gid[lay]->gid) % MAP.gid[lay]->offset)
#define RECT_TOP 32 * \
((layers->map[y][x] - MAP.gid[lay]->gid) / MAP.gid[lay]->offset);
#define RECT_BASE (sfIntRect){0, 0, 32, 16}
#define RECT_OBJ (sfIntRect){0, 0, 32, 64}
#define NB_KEYS 6
#define AUB_POS (sfVector2f){9886, 1456}
#define NB_HOUSE 15
#define OBJ_RECT obj[i]->rectangle
#define MOVE_N (long) update_time(NULL)
#define SETT settings_str
#define ENTXT1 ennemi_text[fight->text_index][GAME.language]
#define ENDTXT end_text[end->language][index]
#define ENDTXT2 end_text[end->language][end->end_status]

#endif /* !MACROS_H_ */
