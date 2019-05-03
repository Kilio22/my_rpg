/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** manage_fight
*/

#include "rpg.h"

static void reset_allie_pos(obj_t **obj, fight_t *fight, rpg_t *rpg, int i)
{
    if (fight->fight_status == 4) {
        if (obj[i]->pos.x <= 13648) {
            fight->fight_status = 0;
            sfSprite_move(obj[i]->sprite, V2F(4 * update_time(NULL), 0));
            choose_fighter(obj, fight, rpg, 2);
        } else
            sfSprite_move(obj[i]->sprite, V2F(-2 * MOVE_N, 0));
    }
    obj[0]->pos = sfSprite_getPosition(obj[i]->sprite);
}

void manage_fight_allies(obj_t **obj, fight_t *fight, rpg_t *rpg, int i)
{
    if (fight->fight_status == 1) {
        if (obj[i]->pos.x >= 13850)
            fight->fight_status++;
        else
            sfSprite_move(obj[i]->sprite, V2F(2 * update_time(NULL), 0));
    }
    if (fight->fight_status == 2) {
        sfSound_play(rpg->music.hurt);
        fight->fight_status++;
    }
    if (fight->fight_status != 3 && fight->fight_status > 0)
        clock_text_intro(0);
    if (fight->fight_status == 3 && clock_text_intro(1) == 1) {
        attack_allies(obj, fight, i, rpg);
        fight->fight_status++;
    }
    reset_allie_pos(obj, fight, rpg, i);
}

static void reset_ennemi_pos(obj_t **obj, fight_t *fight, rpg_t *rpg, int i)
{
    if (fight->fight_status == 4) {
        if (obj[i]->pos.x >= 13890) {
            fight->fight_status = 0;
            sfSprite_move(obj[i]->sprite, V2F(-4 * MOVE_N, 0));
            choose_fighter(obj, fight, rpg, 2);
        } else
            sfSprite_move(obj[i]->sprite, V2F(2 * update_time(NULL), 0));
    }
    obj[i]->pos = sfSprite_getPosition(obj[i]->sprite);
}

void manage_fight_ennemis(obj_t **obj, fight_t *fight, rpg_t *rpg, int i)
{
    obj[i]->oldPos = sfSprite_getPosition(obj[i]->sprite);
    if (fight->fight_status == 1 && fight->life[1] != 0) {
        if (obj[i]->pos.x <= 13690)
            fight->fight_status++;
        else {
            sfSprite_move(obj[i]->sprite, V2F(-2 * MOVE_N, 0));
        }
    }
    if (fight->fight_status == 2) {
        sfSound_play(rpg->music.hurt);
        fight->fight_status++;
    }
    if (fight->fight_status != 3 && fight->fight_status > 0)
        clock_text_intro(0);
    if (fight->fight_status == 3 && clock_text_intro(1) == 1) {
        attack_ennemi(obj, fight);
        fight->fight_status++;
    }
    reset_ennemi_pos(obj, fight, rpg, i);
}

void choose_fighter(obj_t **obj, fight_t *fight, rpg_t *rpg, int i)
{
    static int turn = -1;

    if (i == 0) {
        turn = -1;
        return;
    }
    if (i == 2) {
        turn = fight_turn(obj, fight, 0);
        fight->turn = turn;
        if (turn == fight->nb_fight + 6
&& fight->life[0] != 0 && fight->life[0] !=0) {
            fight->fight_status = 1;
            return;
        }
        update_choices(fight, turn, rpg);
        return;
    }
    if (((fight->life[0] != 0 && fight->life[1] != 0)
|| fight->fight_status != 0) && fight->quest_status == 3)
        apply_attack(obj, fight, rpg, turn);
}