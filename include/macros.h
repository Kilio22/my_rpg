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
#define GAME rpg->game
#define CONTROLS rpg->controls
#define WIND rpg->wind
#define MENU rpg->menu
#define MAP rpg->map
#define MENU_FONT "assets/menu_font_h.ttf"
#define BACK_SETT "assets/settings.png"
#define BACK_CTRL "assets/skyfullofstar.png"

#endif /* !MACROS_H_ */
