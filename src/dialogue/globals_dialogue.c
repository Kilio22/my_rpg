/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** gloabal_dialogues
*/

#include "rpg.h"

const char *welcome[][2] = {
    {"Bienvenue dans mon auberge, que puis-je faire pour vous ?",
    "Welcome to my inn, what can i do for you ?"}
};

const char *dial[][2][3] = {
    {{"Indice Quete",
    "Sauvegarder",
    "Retour"},
    {"Quest clue",
    "Save",
    "Return"}}
};

const char *answers[][2][2] = {
    {
        {"Ah c'est vous qui vous etes fait casser la figure, \n"
    "J'ai entendu dire que l'un d'eux etait sorti de la\n"
    "ville et avait pris la direction du Sud.",
    "Sauvegarde en cours, veuillez patienter..."},
        {"Oh it is you who got beat up, \n"
    "I heard that one of them had left the city \n"
    "and had taken the direction of the South.",
    "Backup in progress, please wait..."}
    }
};