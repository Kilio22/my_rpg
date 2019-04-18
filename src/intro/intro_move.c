/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** intro_move
*/

#include "rpg.h"

void display_house_intro(obj_t **obj, house_t *house, rpg_t *rpg, int *opt)
{
    (void)obj;
    (void)rpg;
    if (house->frame_animation > 8 && house->door_rect.left < 384 - 96) {
        animation(&house->door_rect, 0, 96, 384);
        house->frame_animation = 0;
    }
    house->frame_animation++;
    if (house->door_rect.left > 384 - 97) {
        house->display_house = 0;
        (*opt)++;
    }
}

void check_house_display_intro(obj_t **obj, house_t *house,
rpg_t *rpg, int *opt)
{
    if (house->display_house == 1)
        display_house_intro(obj, house, rpg, opt);
    else
        exit_house(obj[8], house, rpg);
}

void intro_fcts(rpg_t *rpg, obj_t **obj, house_t **house)
{
    static int opt = 0;

    opt = intro[opt](obj, opt, rpg, house);
}

void update_text_pos(rpg_t *rpg, obj_t **obj, intro_t *intro)
{
    sfVector2f vect;

    if (rpg->quest_status == 0 || rpg->quest_status == 2) {
        vect = sfSprite_getPosition(obj[6]->sprite);
        vect.y -= 100;
    } else if ((rpg->quest_status >= 6 && rpg->quest_status <= 9)) {
        vect = sfSprite_getPosition(obj[8]->sprite);
        vect.y -= 50;
    } else {
        vect = sfSprite_getPosition(obj[0]->sprite);
        vect.x += 50;
        vect.y -= 50;
    }
    if (rpg->quest_status >= 11 && rpg->quest_status < 24) {
        if (rpg->quest_status == 11)
            vect = sfSprite_getPosition(obj[9]->sprite);
        else
            vect = sfSprite_getPosition(obj[8]->sprite);
        vect.y -= 70;
        vect.x -= 200;
    }
    if (sfSprite_getPosition(obj[0]->sprite).y <= 1900)
        update_intro_text(rpg, 1, intro);
    sfText_setPosition(intro->text, vect);
}

void intro_action(rpg_t *rpg, obj_t **obj, house_t **house, intro_t *intro)
{
    if (check_characters_clock(obj[1]->clock, 10000.0) == 0) {
        intro_fcts(rpg, obj, house);
        all_character_animation(obj);
    }
    sfSprite_setPosition(obj[1]->sprite,
    sfSprite_getPosition(obj[HERO_HB]->sprite));
    house_interaction(obj[HERO_HB], house, rpg);
    camera_control(rpg, obj[HERO_HB]->pos, obj);
    update_all_rect(obj, house);
    update_text_pos(rpg, obj, intro);
}