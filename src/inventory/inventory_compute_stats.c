/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** inventory_compute_stats
*/

#include "inventory.h"

int compute_attack_stat(inventory_t *inv, int nb_char)
{
    int attack = 0;

    for (int i = 0; i < 6; i++) {
        if (inv->stuff[nb_char][i] == NULL)
            continue;
        attack += inv->stuff[nb_char][i]->attack;
    }
    return (attack);
}

int compute_health_stat(inventory_t *inv, int nb_char)
{
    int health = 0;

    for (int i = 0; i < 6; i++) {
        if (inv->stuff[nb_char][i] == NULL)
            continue;
        health += inv->stuff[nb_char][i]->hp;
    }
    return (health);
}