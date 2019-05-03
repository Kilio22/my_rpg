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
    if (clock_door() == 1 && house->door_rect.left < 384 - 96)
        animation(&house->door_rect, 0, 96, 384);
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

void intro_fcts(rpg_t *rpg, obj_t **obj, house_t **house, intro_t *intros)
{
    static int opt = 0;

    if (intros == NULL) {
        opt = 0;
        return;
    }
    if (rpg->quest_status == 20)
        if (sfMusic_getStatus(GAME.back_music) == sfPlaying)
            sfSound_play(rpg->music.aled);
    opt = intro[opt](obj, opt, rpg, house);
    intros->opt = opt;
}

void update_text_pos(rpg_t *rpg, obj_t **obj, intro_t *intro)
{
    sfVector2f vect = sfRenderWindow_mapPixelToCoords(WIND.wind,
(sfVector2i){0, 558}, WIND.view);

    vect.y += 15;
    vect.x += 80;
    if (sfSprite_getPosition(obj[0]->sprite).y <= 2220)
        update_intro_text(rpg, intro);
    sfText_setPosition(intro->text, vect);
    vect.y -= 15;
    vect.x -= 20;
    sfSprite_setPosition(intro->sprite, vect);
}

void intro_action(rpg_t *rpg, obj_t **obj, house_t **house, intro_t *intro)
{
    intro_fcts(rpg, obj, house, intro);
    all_character_animation_intro(rpg, obj);
    sfSprite_setPosition(obj[1]->sprite,
    sfSprite_getPosition(obj[HERO_HB]->sprite));
    camera_control(rpg, obj[HERO_HB]->pos, obj);
    update_all_rect(obj, house);
    update_text_pos(rpg, obj, intro);
}