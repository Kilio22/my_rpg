/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** intro_move
*/

#include "rpg.h"

static void intro_ennemi_ctrl(obj_t **obj, int *opt, sfVector2f *new_pos)
{
    if (*opt == 2) {
        if (obj[0]->pos.y > 1900) {
            (*new_pos).y -= 1;
            sfSprite_move(obj[0]->sprite, *new_pos);
            obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
            (*new_pos).y += 2;
            sfSprite_move(obj[5]->sprite, *new_pos);
            sfSprite_move(obj[6]->sprite, *new_pos);
            sfSprite_move(obj[7]->sprite, *new_pos);
        } else
            *opt++;
    }
}

void intro_control(obj_t **obj)
{
    static int opt = 0;
    sfVector2f new_pos = {0, 0};

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
    intro_ennemi_ctrl(obj, &opt, &new_pos);
    return;
}

void intro_action(rpg_t *rpg, obj_t **obj, house_t **house)
{
    if (check_characters_clock(obj[1]->clock, 10000.0) == 0) {
        intro_control(obj);
        all_character_animation(obj);
    }
    sfSprite_setPosition(obj[1]->sprite,
    sfSprite_getPosition(obj[HERO_HB]->sprite));
    house_interaction(obj[HERO_HB], house, rpg);
    camera_control(rpg, obj[HERO_HB]->pos, obj);
    update_all_rect(obj, house);
}