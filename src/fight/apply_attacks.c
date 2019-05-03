/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** apply_attacks
*/

#include "inventory.h"
#include "rpg.h"

static int my_attack(rpg_t *rpg, obj_t **obj, int i)
{
    int attack = 0;

    attack += obj[i]->stats[ATK];
    i = (i == 0) ? 0 : i - 1;
    attack += compute_attack_stat(GAME.inv, i);
    return (attack + 1);
}

void attack_allies(obj_t **obj, fight_t *fight, int i, rpg_t *rpg)
{
    int damages = 0;

    if (fight->high == 0)
        damages = global_damages[i][0] +
(rand() % my_attack(rpg, obj, i));
    else {
        if (i == 2)
            damages = ((rand() % 2) == 0) ? 0 : global_damages[i][1];
        else
            damages = global_damages[i][1] +
(rand() % my_attack(rpg, obj, i));
        fight->life[0] = (fight->life[0] < 5) ? 0 : fight->life[0] - 5;
    }
    damages -= rand() % (obj[fight->nb_fight + 6]->stats[DEF] + 1);
    damages = (damages < 0) ? 0 : damages;
    fight->life[1] -= damages;
    fight->life[1] = (fight->life[1] < 0) ? 0 : fight->life[1];
}

void attack_ennemi(obj_t **obj, fight_t *fight)
{
    int i = rand() % 5;
    int damages;

    if (i <= 2)
        damages = global_damages[fight->nb_fight + 3][0] +
(rand() % (obj[fight->nb_fight + 6]->stats[ATK] + 1));
    else
        damages = global_damages[fight->nb_fight + 3][1] +
(rand() % (obj[fight->nb_fight + 6]->stats[ATK] + 1));
    damages -= rand() % (obj[0]->stats[DEF] + 1);
    damages = (damages < 0) ? 0 : damages;
    fight->life[0] -= damages;
    fight->life[0] = (fight->life[0] < 0) ? 0 : fight->life[0];
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