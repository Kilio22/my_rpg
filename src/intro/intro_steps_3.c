/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** intro_steps_3
*/

#include "rpg.h"

int intro_go_auberge8(obj_t **obj, int opt, rpg_t *rpg, house_t **house)
{
    sfVector2f new_pos = {0, 0};

    (void)rpg;
    (void)house;
    if (opt == 22) {
        if (obj[0]->pos.x > 10834) {
            new_pos.y = 1;
            sfSprite_move(obj[8]->sprite, new_pos);
            new_pos.x = -1;
            new_pos.y = 0;
            sfSprite_move(obj[0]->sprite, new_pos);
            obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        } else
            opt++;
    }
    return opt;
}

int intro_go_auberge7(obj_t **obj, int opt, rpg_t *rpg, house_t **house)
{
    sfVector2f new_pos = {0, 0};

    (void)rpg;
    (void)house;
    if (opt == 21) {
        if (obj[8]->pos.x > 10834) {
            new_pos.x = -1;
            sfSprite_move(obj[8]->sprite, new_pos);
            sfSprite_move(obj[0]->sprite, new_pos);
            obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        } else
            opt++;
    }
    return opt;
}

int intro_go_auberge6(obj_t **obj, int opt, rpg_t *rpg, house_t **house)
{
    sfVector2f new_pos = {0, 0};

    (void)rpg;
    (void)house;
    if (opt == 20) {
        if (obj[0]->pos.y < 1104) {
            new_pos.x = -1;
            sfSprite_move(obj[8]->sprite, new_pos);
            new_pos.x = 0;
            new_pos.y = 1;
            sfSprite_move(obj[0]->sprite, new_pos);
            obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        } else
            opt++;
    }
    return opt;
}

int intro_go_auberge5(obj_t **obj, int opt, rpg_t *rpg, house_t **house)
{
    sfVector2f new_pos = {0, 0};

    (void)rpg;
    (void)house;
    if (opt == 19) {
        if (obj[8]->pos.y < 1076) {
            new_pos.y = 1;
            sfSprite_move(obj[8]->sprite, new_pos);
            sfSprite_move(obj[0]->sprite, new_pos);
            obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        } else
            opt++;
    }
    return opt;
}

int intro_go_auberge4(obj_t **obj, int opt, rpg_t *rpg, house_t **house)
{
    sfVector2f new_pos = {0, 0};

    (void)rpg;
    (void)house;
    if (opt == 18) {
        if (obj[0]->pos.x > 11376) {
            new_pos.y = 1;
            sfSprite_move(obj[8]->sprite, new_pos);
            new_pos.y = 0;
            new_pos.x = -1;
            sfSprite_move(obj[0]->sprite, new_pos);
            obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        } else
            opt++;
    }
    return opt;
}