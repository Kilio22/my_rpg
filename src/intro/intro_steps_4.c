/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** intro_steps_4
*/

#include "rpg.h"

int intro_go_auberge13(obj_t **obj, int opt, rpg_t *rpg, house_t **house)
{
    sfVector2f new_pos = {0, 0};
    (void)rpg;
    if (opt == 27) {
        if (obj[8]->pos.y > 1512) {
            new_pos.y = -1;
            sfSprite_move(obj[8]->sprite, new_pos);
            sfSprite_move(obj[0]->sprite, new_pos);
            obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        } else
            opt++;
    }
    if (opt == 28) {
        house[0]->display_house = 1;
        check_house_display_intro(obj, house[0], rpg, &opt);
    }
    return opt;
}

int intro_go_auberge12(obj_t **obj, int opt, rpg_t *rpg, house_t **house)
{
    sfVector2f new_pos = {0, 0};

    (void)rpg;
    (void)house;
    if (opt == 26) {
        if (obj[0]->pos.x > 10048) {
            new_pos.y = -1;
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

int intro_go_auberge11(obj_t **obj, int opt, rpg_t *rpg, house_t **house)
{
    sfVector2f new_pos = {0, 0};

    (void)rpg;
    (void)house;
    if (opt == 25) {
        if (obj[8]->pos.x > 10048) {
            new_pos.x = -1;
            sfSprite_move(obj[8]->sprite, new_pos);
            sfSprite_move(obj[0]->sprite, new_pos);
            obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        } else
            opt++;
    }
    return opt;
}

int intro_go_auberge10(obj_t **obj, int opt, rpg_t *rpg, house_t **house)
{
    sfVector2f new_pos = {0, 0};

    (void)rpg;
    (void)house;
    if (opt == 24) {
        if (obj[0]->pos.y < 1616) {
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

int intro_go_auberge9(obj_t **obj, int opt, rpg_t *rpg, house_t **house)
{
    sfVector2f new_pos = {0, 0};

    (void)rpg;
    (void)house;
    if (opt == 23) {
        if (obj[8]->pos.y < 1588) {
            new_pos.y = 1;
            sfSprite_move(obj[8]->sprite, new_pos);
            sfSprite_move(obj[0]->sprite, new_pos);
            obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        } else
            opt++;
    }
    return opt;
}