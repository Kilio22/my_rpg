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
        if (obj[8]->pos.x > 11376) {
            new_pos.x = -1;
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
        if (obj[8]->pos.x > 11436) {
            new_pos.x = -1;
            sfSprite_move(obj[8]->sprite, new_pos);
        } else
            opt++;
    }
    if (opt == 16) {
        if (obj[0]->pos.y > 910) {
            new_pos.y = -1;
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
        if (obj[8]->pos.y > 882) {
            new_pos.y = -1;
            sfSprite_move(obj[8]->sprite, new_pos);
        } else
            opt++;
    }
    if (opt == 14) {
        if (obj[0]->pos.x > 11500) {
            new_pos.x = -1;
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
        if (obj[8]->pos.x < 11502) {
            new_pos.x = 1;
            sfSprite_move(obj[8]->sprite, new_pos);
            new_pos.x = -1;
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
        if (obj[8]->pos.x < 11500) {
            new_pos.x = 1;
            sfSprite_move(obj[8]->sprite, new_pos);
        } else
            opt++;
    }
    if (opt == 11) {
        if (obj[8]->pos.y < 1096) {
            new_pos.y = 1;
            sfSprite_move(obj[8]->sprite, new_pos);
        } else
            opt++;
    }
    return opt;
}