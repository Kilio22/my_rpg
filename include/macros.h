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
((layers->map[y][x] - MAP.gid[l]->gid) % MAP.gid[l]->offset)
#define RECT_TOP 32 * \
((layers->map[y][x] - MAP.gid[l]->gid) / MAP.gid[l]->offset);
#define RECT_BASE (sfIntRect){0, 0, 32, 16}
#define RECT_OBJ (sfIntRect){0, 0, 32, 64}
#define NB_KEYS 5
#define AUB_POS (sfVector2f){9886, 1456}
#define NB_HOUSE 15
#define OBJ_RECT obj[i]->rectangle

#endif /* !MACROS_H_ */
