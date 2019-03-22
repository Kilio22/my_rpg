/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** globals
*/

#include "rpg.h"

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