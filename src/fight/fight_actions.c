/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** fight_actions
*/

#include "rpg.h"

static void update_text_pos(fight_t *fight, rpg_t *rpg)
{
    sfVector2f vect = sfRenderWindow_mapPixelToCoords(WIND.wind,
(sfVector2i){0, 558}, WIND.view);

    if (fight->quest_status == 8) {
        fight->text_index = (fight->win == 1) ? 3 : 4;
        update_fight_text(fight, 1, rpg);
        fight->quest_status++;
    }
    if (fight->old_i == fight->nb_fight || fight->quest_status == 9)
        update_fight_text(fight, 0, rpg);
    vect.y += 15;
    vect.x += 80;
    sfText_setPosition(fight->text, vect);
    vect.y -= 15;
    vect.x -= 20;
    sfSprite_setPosition(fight->parch, vect);
}

static void update_perso_pos(obj_t **obj, fight_t *fight)
{
    sfVector2f vect = {13650, 500};
    sfVector2f vect2 = {13650, 440};
    sfVector2f vect3 = {13650, 560};
    sfVector2f vect4 = {13890, 500};

    if (fight->quest_status == 2) {
        sfSprite_setPosition(obj[HERO_HB]->sprite, vect);
        obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
        obj[1]->sprite_rect.top = 0;
        sfSprite_setPosition(obj[2]->sprite, vect2);
        obj[2]->pos = sfSprite_getPosition(obj[2]->sprite);
        obj[2]->sprite_rect.top = 0;
        sfSprite_setPosition(obj[3]->sprite, vect3);
        obj[3]->pos = sfSprite_getPosition(obj[3]->sprite);
        obj[3]->sprite_rect.top = 0;
        sfSprite_setPosition(obj[fight->nb_fight + 6]->sprite, vect4);
        obj[fight->nb_fight + 6]->sprite_rect.top = 64;
    }
}

static void update_perso(rpg_t *rpg, obj_t **obj,
house_t **house, fight_t *fight)
{
    update_perso_pos(obj, fight);
    choose_fighter(obj, fight, rpg, 3);
    if (fight->life[0] == 0 && fight->quest_status == 3) {
        fight->quest_status++;
        fight->win = 1;
    } else if (fight->life[1] == 0 && fight->quest_status == 3) {
        fight->quest_status++;
        fight->win = 2;
    }
    check_end_pos(fight, obj, house, rpg);
    for (int i = 0; i < 5; i++)
        update_attacks_pos(fight, rpg, i);
    update_attacks_pos(fight, rpg, -1);
    positioning_life_perso(fight, rpg);
    sfSprite_setPosition(obj[1]->sprite,
    sfSprite_getPosition(obj[HERO_HB]->sprite));
}

void fight_action(rpg_t *rpg, obj_t **obj, house_t **house, fight_t *fight)
{
    all_character_animation(obj);
    update_perso(rpg, obj, house, fight);
    obj[0]->pos = sfSprite_getPosition(obj[0]->sprite);
    if (fight->quest_status > 1 && fight->quest_status < 6)
        fight_camera_control(rpg, V2F(13756, 500), obj);
    else
        fight_camera_control(rpg, obj[HERO_HB]->pos, obj);
    update_all_rect(obj, house);
    update_text_pos(fight, rpg);
    update_fondu_rect_fight(fight, rpg, 0);
}