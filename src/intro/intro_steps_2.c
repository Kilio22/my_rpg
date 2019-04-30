/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** intro_steps_2
*/

#include "rpg.h"

int intro_go_auberge3(obj_t **obj, int opt, rpg_t *rpg, house_t **house)
{
    sfVector2f new_pos = {0, 0};

    (void)rpg;
    (void)house;
    if (opt == 17) {
        if (obj[8]->pos.x > 12016) {
            new_pos.x = -2 * MOVE_N;
            sfSprite_move(obj[8]->sprite, new_pos);
            sfSprite_move(obj[0]->sprite, new_pos);
            obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        } else
            opt++;
    }
    return opt;
}

int intro_go_auberge2(obj_t **obj, int opt, rpg_t *rpg, house_t **house)
{
    sfVector2f new_pos = {0, 0};

    (void)rpg;
    (void)house;
    if (opt == 15) {
        if (obj[8]->pos.x > 12076) {
            new_pos.x = -2 * MOVE_N;
            sfSprite_move(obj[8]->sprite, new_pos);
        } else
            opt++;
    }
    if (opt == 16) {
        if (obj[0]->pos.y > 1230) {
            new_pos.y = -2 * MOVE_N;
            sfSprite_move(obj[0]->sprite, new_pos);
            obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        } else
            opt++;
    }
    return opt;
}

int intro_go_auberge(obj_t **obj, int opt, rpg_t *rpg, house_t **house)
{
    sfVector2f new_pos = {0, 0};

    (void)house;
    if (opt == 13 && rpg->quest_status == 10) {
        if (obj[8]->pos.y > 1202) {
            new_pos.y = -2 * MOVE_N;
            sfSprite_move(obj[8]->sprite, new_pos);
        } else
            opt++;
    }
    if (opt == 14) {
        if (obj[0]->pos.x > 12140) {
            new_pos.x = -2 * MOVE_N;
            sfSprite_move(obj[0]->sprite, new_pos);
            obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        } else
            opt++;
    }
    return opt;
}

int intro_nathan_dialogue(obj_t **obj, int opt, rpg_t *rpg, house_t **house)
{
    sfVector2f new_pos = {0, 0};

    (void)house;
    if (opt == 12) {
        if (obj[8]->pos.x < 12142) {
            new_pos.x = 2 * MOVE_N;
            sfSprite_move(obj[8]->sprite, new_pos);
            new_pos.x = -2 * MOVE_N;
            sfSprite_move(obj[0]->sprite, new_pos);
            obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        } else {
            rpg->quest_status++;
            clock_text_intro(0);
            opt++;
        }
    }
    return opt;
}

int intro_nathan_echelle(obj_t **obj, int opt, rpg_t *rpg, house_t **house)
{
    sfVector2f new_pos = {0, 0};

    (void)house;
    (void)rpg;
    if (opt == 10) {
        if (obj[8]->pos.x < 12140) {
            new_pos.x = 2 * MOVE_N;
            sfSprite_move(obj[8]->sprite, new_pos);
        } else
            opt++;
    }
    if (opt == 11) {
        if (obj[8]->pos.y < 1416) {
            new_pos.y = 2 * MOVE_N;
            sfSprite_move(obj[8]->sprite, new_pos);
        } else
            opt++;
    }
    return opt;
}