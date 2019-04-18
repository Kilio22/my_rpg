/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** intro_steps_5
*/

#include "rpg.h"

int intro_go_auberge18(obj_t **obj, int opt, rpg_t *rpg, house_t **house)
{
    sfVector2f new_pos = {0, 0};

    (void)house;
    if (opt == 38) {
        if (obj[0]->pos.y > 1130) {
            new_pos.y = -1;
            sfSprite_move(obj[0]->sprite, new_pos);
            obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        } else {
            rpg->quest_status++;
            opt++;
        }
    }
    return opt;
}

int intro_go_auberge17(obj_t **obj, int opt, rpg_t *rpg, house_t **house)
{
    sfVector2f new_pos = {0, 0};

    (void)house;
    if (opt == 36 && rpg->quest_status == 14) {
        if (obj[0]->pos.y < 1150) {
            new_pos.y = 1;
            sfSprite_move(obj[0]->sprite, new_pos);
            obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        } else
            opt++;
    }
    if (opt == 37) {
        if (obj[0]->pos.x < 9408) {
            new_pos.x = 1;
            sfSprite_move(obj[0]->sprite, new_pos);
            obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        } else
            opt++;
    }
    return opt;
}

int intro_go_auberge16(obj_t **obj, int opt, rpg_t *rpg, house_t **house)
{
    sfVector2f new_pos = {0, 0};

    (void)house;
    if (opt == 33) {
        if (obj[0]->pos.y > 1000) {
            new_pos.y = -1;
            sfSprite_move(obj[0]->sprite, new_pos);
            obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        } else
            opt++;
    }
    if ((opt == 34 || opt == 35) && rpg->quest_status == 13) {
        new_pos.x = -1;
        sfSprite_move(obj[10]->sprite, new_pos);
        new_pos.x = 0;
        new_pos.y = 1;
        sfSprite_move(obj[0]->sprite, new_pos);
        obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        opt++;
    }
    return opt;
}

int intro_go_auberge15(obj_t **obj, int opt, rpg_t *rpg, house_t **house)
{
    sfVector2f new_pos = {0, 0};

    (void)house;
    if (opt == 32) {
        if (obj[0]->pos.x > 9266) {
            new_pos.x = -1;
            sfSprite_move(obj[0]->sprite, new_pos);
            obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        } else {
            opt++;
            rpg->quest_status++;
        }
    }
    return opt;
}

int intro_go_auberge14(obj_t **obj, int opt, rpg_t *rpg, house_t **house)
{
    sfVector2f new_pos = {0, 0};

    (void)house;
    if (opt == 29) {
        if (obj[8]->pos.y > 1060) {
            new_pos.y = -1;
            sfSprite_move(obj[8]->sprite, new_pos);
            sfSprite_move(obj[0]->sprite, new_pos);
            obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        } else {
            opt++;
            rpg->quest_status++;
        }
    }
    if (opt == 30 || opt == 31) {
        new_pos.y = 1;
        sfSprite_move(obj[8]->sprite, new_pos);
        opt++;
    }
    return opt;
}