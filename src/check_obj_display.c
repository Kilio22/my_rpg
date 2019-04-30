/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** check_obj_display
*/

#include "rpg.h"

static void check_pos_objs(obj_t **obj, int *n_val)
{
    float lowest_dist = -1;

    for (int i = 5; i < 9; i++) {
        if (obj[i] == NULL)
            continue;
        lowest_dist = calc_dist(obj[0]->pos, obj[i]->pos);
        *n_val = i;
        break;
    }
    if (lowest_dist == -1)
        return;
    for (int i = *n_val + 1; i < 9; i++) {
        if (obj[i] == NULL)
            continue;
        if (calc_dist(obj[0]->pos, obj[i]->pos) < lowest_dist) {
            *n_val = i;
            lowest_dist = calc_dist(obj[0]->pos, obj[i]->pos);
        }
    }
}

void check_obj_display(obj_t **obj, rpg_t *rpg)
{
    int n_val = -1;

    check_pos_objs(obj, &n_val);
    if (n_val == -1) {
        print_reverse_order(obj, rpg);
        return;
    }
    if (obj[0]->pos.y >= obj[n_val]->pos.y)
        n_val = -1;
    if (n_val > 0)
        print_reverse_order(obj, rpg);
    else
        print_base_order(obj, rpg);
}