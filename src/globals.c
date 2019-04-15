/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** globals
*/

#include "rpg.h"

const char *menu_path[2] = {
    "assets/background_menu.png",
    "assets/load.png"
};

const char *menu_str[6] = {
    " New Game ",
    " Load Game ",
    "   Settings ",
    "How To Play ",
    "   Credits ",
    "     Quit "
};

const sfVector2f menu_pos[6] = {
    {110, 60},
    {100, 160},
    {100, 260},
    {100, 360},
    {115, 460},
    {90, 560}
};

const char *save_path[3] = {
    "saves/save1.txt",
    "saves/save2.txt",
    "saves/save3.txt"
};

const char *house_path[4] = {
    "assets/maison1.png",
    "assets/maison2.png",
    "assets/auberge.png",
    "assets/forge.png"
};

const sfIntRect house_rects[4] = {
    {0, 0, 160, 320},
    {0, 0, 224, 256},
    {0, 0, 320, 448},
    {0, 0, 192, 352}
};

const sfVector2f door_pos[4] = {
    {0, 256},
    {0, 192},
    {160, 352},
    {95, 160}
};

const sfIntRect door_rects[4] = {
    {0, 64, 96, 64},
    {0, 0, 96, 64},
    {0, 352, 96, 96},
    {0, 224, 96, 64},
};

void (* const menu[6])(rpg_t *, obj_t **, house_t **) = {
    menu_new_game,
    menu_load_game,
    menu_settings,
    menu_how_to_play,
    menu_credit,
    menu_close_window
};
