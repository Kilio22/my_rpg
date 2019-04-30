/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** sort
*/

#include "rpg.h"

static int is_sorted(int (*tab)[4])
{
    for (size_t i = 0; i < 3; i++)
        if ((*tab)[i] < (*tab)[i + 1])
            return -1;
    return 0;
}

static void sorter_action(int (*tab)[4], int (*tab_speed)[4])
{
    int tmp;

    for (size_t i = 0; i < 3; i++) {
        if ((*tab_speed)[i] < (*tab_speed)[i + 1]) {
            tmp = (*tab_speed)[i];
            (*tab_speed)[i] = (*tab_speed)[i + 1];
            (*tab_speed)[i + 1] = tmp;
            tmp = (*tab)[i];
            (*tab)[i] = (*tab)[i + 1];
            (*tab)[i + 1] = tmp;
        }
    }
}

void sorter(int (*tab)[4], int (*tab_speed)[4])
{
    while (is_sorted(tab_speed) == -1)
        sorter_action(tab, tab_speed);
}
