/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** fight_order
*/

#include "rpg.h"

void init_order(obj_t **obj, fight_t *fight, int (*order)[4])
{
    int speeds[4] = {-1, -1, -1, -1};

    (*order)[0] = 0;
    (*order)[1] = 2;
    (*order)[2] = 3;
    (*order)[3] = fight->nb_fight + 6;
    speeds[0] = obj[0]->stats[SPEED];
    speeds[1] = obj[2]->stats[SPEED];
    speeds[2] = obj[3]->stats[SPEED];
    speeds[3] = obj[fight->nb_fight + 6]->stats[SPEED];
    sorter(order, &speeds);
}

int fight_turn(obj_t **obj, fight_t *fight, int i)
{
    static int turn = -1;
    static int order[4] = {-1, -1, -1, -1};

    if (i == 1) {
        turn = -1;
        return 0;
    }
    if (turn == -1) {
        init_order(obj, fight, &order);
        turn = 0;
    }
    else {
        if (turn == 3)
            turn = 0;
        else
            turn++;
    }
    return order[turn];
}