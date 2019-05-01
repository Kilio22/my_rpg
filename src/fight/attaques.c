/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** attaques
*/

#include "rpg.h"

const char *attaques_names[][5] = {
    {"Coup Epee",
    "DuoStumper",
    "Fuir",
    "ALLIES : 300",
    "ENNEMI : 100"},
    {"Pichnette",
    "Pile ou face",
    "Fuir",
    "ALLIES : 100",
    "ENNEMI : 100"},
    {"Rate-attak",
    "Coude'bool",
    "Fuir",
    "ALLIES : 100",
    "ENNEMI : 100"}
};

const int global_damages[6][2] = {
    {7, 14},
    {2, 20},
    {5, 15},
    {5, 8},
    {8, 13},
    {12, 18}
};