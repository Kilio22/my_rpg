/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** gloabal_dialogues
*/

#include "rpg.h"

const char *welcome[][2] = {
    {"Bienvenue dans mon auberge, que puis-je faire pour vous ?",
    "Welcome to my inn, what can i do for you ?"},
    {"Bienvenue dans ma forge, que puis-je faire pour vous ?",
    "Welcome to my smithy, what can i do for you ?"}
};

const char *dial[][2][3] = {
    {{"Indice Quete",
    "Sauvegarder",
    "Retour"},
    {"Quest clue",
    "Save",
    "Return"}},
    {{"Indice Quete",
    "Discussion",
    "Retour"},
    {"Quest clue",
    "Discussion",
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
    },
    {
        {"J'ai entendu parler de votre histoire..., \n"
    "J'ai cru voir l'un d'entre eux sortir de la\n"
    "ville et partir vers le Nord Ouest.",
    "Je dirige cette forge depuis ma jeunnesse! Ici, je fabrique\n"
    "des epees pour les plus valeureux combattans de la ville"},
        {"I heard about your story ..., \n"
    "I think I saw one of them coming out of the\n"
    "city and go to the North West.",
    "I manage this smithy since my youth! Here, I make swords\n"
    "for the bravest fighters of the city"}
    }
};