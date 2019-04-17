/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** intro_move
*/

#include "rpg.h"

static int intro_port(obj_t **obj, int opt, rpg_t *rpg)
{
    sfVector2f new_pos = {0, 0};

    if (opt == 3 && rpg->quest_status == 3) {
        new_pos.x = 11552;
        new_pos.y = 1094;
        sfSprite_setPosition(obj[0]->sprite, new_pos);
        new_pos.x = -1;
        new_pos.y = 0;
        sfSprite_move(obj[0]->sprite, new_pos);
        obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        opt++;
    }
    return opt;
}

static int intro_ennemi_ctrl(obj_t **obj, int opt, rpg_t *rpg)
{
    sfVector2f new_pos = {0, 0};

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
    return (intro_port(obj, opt, rpg));
}

void intro_control(obj_t **obj, rpg_t *rpg)
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
    opt = intro_ennemi_ctrl(obj, opt, rpg);
    return;
}

void update_text_pos(rpg_t *rpg, obj_t **obj, intro_t *intro)
{
    sfVector2f vect;

    if (rpg->quest_status == 0 || rpg->quest_status == 2) {
        vect = sfSprite_getPosition(obj[6]->sprite);
        vect.y -= 100;
    } else {
        vect.x += 50;
        vect.y -= 50;
        vect = sfSprite_getPosition(obj[0]->sprite);
    }
    if (sfSprite_getPosition(obj[0]->sprite).y <= 1900)
        update_intro_text(rpg, 1, intro);
    sfText_setPosition(intro->text, vect);
}

void intro_action(rpg_t *rpg, obj_t **obj, house_t **house, intro_t *intro)
{
    if (check_characters_clock(obj[1]->clock, 10000.0) == 0) {
        intro_control(obj, rpg);
        all_character_animation(obj);
    }
    sfSprite_setPosition(obj[1]->sprite,
    sfSprite_getPosition(obj[HERO_HB]->sprite));
    house_interaction(obj[HERO_HB], house, rpg);
    camera_control(rpg, obj[HERO_HB]->pos, obj);
    update_all_rect(obj, house);
    update_text_pos(rpg, obj, intro);
}