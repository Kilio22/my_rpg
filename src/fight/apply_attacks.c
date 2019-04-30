/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** apply_attacks
*/

#include "rpg.h"

void attack_allies(obj_t **obj, fight_t *fight, int i)
{
    int damages;

    i = (i == 0) ? 0 : i - 1;
    if (fight->high == 0)
        damages = global_damages[i][0] +
(rand() % obj[i]->stats[ATK]);
    else {
        if (i == 2)
            damages = ((rand() % 2) == 0) ? 0 : global_damages[i][1];
        else
            damages = global_damages[i][1] +
(rand() % obj[i]->stats[ATK]);
        fight->life[0] -= 5;
    }
    damages -= rand() % obj[fight->nb_fight + 6]->stats[DEF];
    fight->life[1] -= damages;
    fight->life[1] = (fight->life[1] < 0 ? 0 : fight->life[1]);
}

void attack_ennemi(obj_t **obj, fight_t *fight)
{
    int i = rand() % 5;
    int damages;

    if (i <= 2)
        damages = global_damages[fight->nb_fight + 3][0] +
(rand() % obj[fight->nb_fight + 6]->stats[ATK]);
    else
        damages = global_damages[fight->nb_fight + 3][0] +
(rand() % obj[fight->nb_fight + 6]->stats[ATK]);
    damages -= rand() % obj[0]->stats[DEF];
    fight->life[0] -= damages;
    fight->life[0] = (fight->life[0] < 0 ? 0 : fight->life[0]);
}

void apply_attack(obj_t **obj, fight_t *fight, rpg_t *rpg, int turn)
{
    if (turn == -1)
        return;
    if (turn == fight->nb_fight + 6)
        manage_fight_ennemis(obj, fight, rpg, turn);
    else
        manage_fight_allies(obj, fight, rpg, turn);
}