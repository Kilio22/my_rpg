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

const char *house_path[2] = {
    "assets/maison 1.png",
    "assets/maison 2.png"
};

const sfIntRect house_rects[2] = {
    {0, 0, 192, 320},
    {0, 0, 256, 256}
};

const char *door_path[2] = {
    "assets/door1.png",
    "assets/door1.png"
};

const sfIntRect door_rects = {0, 0, 96, 96};

const int door_pos[2] = {256, 192};
void (* const menu[6])(rpg_t *, obj_t **, house_t **) = {
    menu_new_game,
    menu_load_game,
    menu_settings,
    menu_how_to_play,
    menu_credit,
    menu_close_window
};
