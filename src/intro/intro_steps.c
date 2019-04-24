/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** intro_steps
*/

#include "rpg.h"

int intro_nathan(obj_t **obj, int opt, rpg_t *rpg, house_t **house)
{
    sfVector2f new_pos = {0, 0};

    (void)house;
    if (opt == 8 && rpg->quest_status == 4) {
        if (obj[8]->pos.x < 11376) {
            new_pos.x = 1;
            sfSprite_move(obj[8]->sprite, new_pos);
        } else
            opt++;
    }
    if (opt == 9) {
        if (obj[8]->pos.y > 882) {
            new_pos.y -= 1;
            sfSprite_move(obj[8]->sprite, new_pos);
        } else {
            rpg->quest_status++;
            clock_text_intro(0);
            opt++;
        }
    }
    return opt;
}

int intro_port(obj_t **obj, int opt, rpg_t *rpg, house_t **house)
{
    sfVector2f new_pos = {0, 0};

    (void)house;
    if (opt == 5 && rpg->quest_status == 3) {
        sfSound_play(rpg->music.hurt);
        new_pos.x = 11556;
        new_pos.y = 1122;
        sfSprite_setPosition(obj[0]->sprite, new_pos);
        obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        opt++;
    }
    if (opt == 6 || opt == 7) {
        new_pos.x = 0;
        new_pos.y = 1;
        sfSprite_move(obj[0]->sprite, new_pos);
        obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        opt++;
    }
    return opt;
}

int intro_ennemi_two(obj_t **obj, int opt, rpg_t *rpg, house_t **house)
{
    sfVector2f new_pos = {0, 0};

    (void)house;
    (void)rpg;
    if (opt == 3  || opt == 4) {
        (new_pos).x -= 1;
        sfSprite_move(obj[6]->sprite, new_pos);
        (new_pos).x += 2;
        sfSprite_move(obj[7]->sprite, new_pos);
        opt++;
    }
    return (opt);
}

int intro_ennemi_ctrl(obj_t **obj, int opt, rpg_t *rpg, house_t **house)
{
    sfVector2f new_pos = {0, 0};

    (void)house;
    (void)rpg;
    if (opt == 2) {
        if (obj[0]->pos.y > 1900) {
            (new_pos).y -= 1;
            sfSprite_move(obj[0]->sprite, new_pos);
            obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
            (new_pos).y += 2;
            sfSprite_move(obj[5]->sprite, new_pos);
            sfSprite_move(obj[6]->sprite, new_pos);
            sfSprite_move(obj[7]->sprite, new_pos);
        } else
            opt++;
    }
    return (intro_ennemi_two(obj, opt, rpg, house));
}

int intro_control(obj_t **obj, int opt, rpg_t *rpg, house_t **house)
{
    sfVector2f new_pos = {0, 0};

    (void)house;
    (void)rpg;
    if (opt == 0) {
        if (obj[0]->pos.y > 2076) {
            new_pos.y -= 1;
            sfSprite_move(obj[0]->sprite, new_pos);
            obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        } else
            opt++;
    }
    if (opt == 1) {
        if (obj[0]->pos.x > 10194) {
            new_pos.x -= 1;
            sfSprite_move(obj[0]->sprite, new_pos);
            obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        } else
            opt++;
    }
    return opt;
}