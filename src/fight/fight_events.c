/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** fight_events
*/

#include "rpg.h"

static void update_text_pos(fight_t *fight, rpg_t *rpg)
{
    sfVector2f vect = sfRenderWindow_mapPixelToCoords(WIND.wind,
(sfVector2i){0, 558}, WIND.view);

    if (fight->old_i == fight->nb_fight)
        update_fight_text(1, fight, 0);
    vect.y += 15;
    vect.x += 80;
    sfText_setPosition(fight->text, vect);
    vect.y -= 15;
    vect.x -= 20;
    sfSprite_setPosition(fight->parch, vect);
}

static void attack_allies(obj_t **obj, fight_t *fight, int i)
{
    int damages;

    i = (i == 0) ? 0 : i - 1;
    if (fight->high == 0)
        damages = global_damages[i][0] +
(rand() % obj[i]->stats[ATK]);
    else {
        if (i == 2)
            damages = ((rand() % 2) == 0) ? 0 : global_damages[i][1];
        else
            damages = global_damages[i][1] +
(rand() % obj[i]->stats[ATK]);
        fight->life[0] -= 5;
    }
    damages -= rand() % obj[fight->nb_fight + 6]->stats[DEF];
    fight->life[1] -= damages;
}

static void manage_fight_allys(obj_t **obj, fight_t *fight, rpg_t *rpg, int i)
{
    if (fight->fight_status == 1) {
        if (obj[i]->pos.x == 13850)
            fight->fight_status++;
        else
            sfSprite_move(obj[i]->sprite, V2F(2, 0));
    }
    if (fight->fight_status == 2) {
        sfSound_play(rpg->music.hurt);
        fight->fight_status++;
    }
    if (fight->fight_status != 3 && fight->fight_status > 0)
        clock_text_intro(0);
    if (fight->fight_status == 3 && clock_text_intro(1) == 1) {
        attack_allies(obj, fight, i);
        fight->fight_status++;
    }
    if (fight->fight_status == 4) {
        if (obj[i]->pos.x <= 13648) {
            fight->fight_status = 0;
            sfSprite_move(obj[i]->sprite, V2F(4, 0));
            choose_fighter(obj, fight, rpg, 2);
        } else
            sfSprite_move(obj[i]->sprite, V2F(-2, 0));
    }
    obj[0]->pos = sfSprite_getPosition(obj[i]->sprite);
}

static void attack_ennemi(obj_t **obj, fight_t *fight)
{
    int i = rand() % 5;
    int damages;

    if (i <= 2)
        damages = global_damages[fight->nb_fight + 3][0] +
(rand() % obj[fight->nb_fight + 6]->stats[ATK]);
    else
        damages = global_damages[fight->nb_fight + 3][0] +
(rand() % obj[fight->nb_fight + 6]->stats[ATK]);
    damages -= rand() % obj[0]->stats[DEF];
    fight->life[0] -= damages;
}

static void manage_fight_ennemis(obj_t **obj, fight_t *fight, rpg_t *rpg, int i)
{
    obj[i]->oldPos = sfSprite_getPosition(obj[i]->sprite);
    if (fight->fight_status == 1) {
        if (obj[i]->pos.x == 13690)
            fight->fight_status++;
        else {
            sfSprite_move(obj[i]->sprite, V2F(-2, 0));
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
    if (fight->fight_status == 4) {
        if (obj[i]->pos.x >= 13890) {
            fight->fight_status = 0;
            sfSprite_move(obj[i]->sprite, V2F(-4, 0));
            choose_fighter(obj, fight, rpg, 2);
        } else
            sfSprite_move(obj[i]->sprite, V2F(2, 0));
    }
    obj[i]->pos = sfSprite_getPosition(obj[i]->sprite);
}

void apply_attack(obj_t **obj, fight_t *fight, rpg_t *rpg, int turn)
{
    if (turn == -1)
        return;
    if (turn == fight->nb_fight + 6)
        manage_fight_ennemis(obj, fight, rpg, turn);
    else
        manage_fight_allys(obj, fight, rpg, turn);
}

void update_choices(fight_t *fight, int turn, rpg_t *rpg)
{
    if (turn == 0) {
        for (int i = 0; i < 5; i++) {
            sfText_setString(fight->attacks[i], attaques_names[0][i]);
            update_attacks_pos(fight, rpg, i);
        }
    } else {
        for (int i = 0; i < 5; i++) {
            sfText_setString(fight->attacks[i], attaques_names[turn - 1][i]);
            update_attacks_pos(fight, rpg, i);
        }
    }
}

void choose_fighter(obj_t **obj, fight_t *fight, rpg_t *rpg, int i)
{
    static int turn = -1;

    if (i == 0) {
        turn = -1;
        return;
    }
    if (i == 1) {
        fight->fight_status = 1;
        return;
    }
    if (i == 2) {
        turn = fight_turn(obj, fight, 0);
        fight->turn = turn;
        if (turn == fight->nb_fight + 6) {
            fight->fight_status = 1;
            return;
        }
        update_choices(fight, turn, rpg);
        return;
    }
    apply_attack(obj, fight, rpg, turn);
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

void fight_action(rpg_t *rpg, obj_t **obj, house_t **house, fight_t *fight)
{
    if (check_characters_clock(obj[1]->clock, 10000.0) == 0)
        all_character_animation(obj);
    update_perso_pos(obj, fight);
    choose_fighter(obj, fight, rpg, 3);
    for (int i = 0; i < 5; i++)
        update_attacks_pos(fight, rpg, i);
    update_attacks_pos(fight, rpg, -1);
    positioning_life_perso(fight, rpg);
    sfSprite_setPosition(obj[1]->sprite,
    sfSprite_getPosition(obj[HERO_HB]->sprite));
    if (fight->quest_status > 1)
        fight_camera_control(rpg, V2F(13756, 500), obj);
    else
        fight_camera_control(rpg, obj[HERO_HB]->pos, obj);
    update_all_rect(obj, house);
    update_text_pos(fight, rpg);
    update_fondu_rect_fight(fight, rpg, 0);
}

static int manage_other_key_press(int code, fight_t *fight, obj_t **obj)
{
    if (fight->quest_status < 3)
        return 0;
    if (code == sfKeyLeft && fight->high > 0 && fight->fight_status == 0 && fight->turn < 6) {
        sfText_setColor(fight->attacks[fight->high], sfRed);
        fight->high--;
        sfText_setColor(fight->attacks[fight->high], sfBlue);
    }
    if (code == sfKeyRight && fight->high < 2 && fight->fight_status == 0 && fight->turn < 6) {
        sfText_setColor(fight->attacks[fight->high], sfRed);
        fight->high++;
        sfText_setColor(fight->attacks[fight->high], sfBlue);
    }
    if (code == sfKeyReturn && fight->fight_status == 0) {
        if (fight->high == 2)
            return 1;
        choose_fighter(obj, fight, NULL, 1);
    }
    return 0;
}

int fight_event_management(rpg_t *rpg, fight_t *fight, obj_t **obj)
{
    if (WIND.event.type == sfEvtMouseMoved) {
        CONTROLS.mousePos.x = WIND.event.mouseMove.x;
        CONTROLS.mousePos.y = WIND.event.mouseMove.y;
    }
    if (WIND.event.type == sfEvtKeyPressed) {
        if (WIND.event.key.code == sfKeyF5)
            set_music(rpg);
        if (WIND.event.key.code == sfKeyEscape)
            return 1;
        return manage_other_key_press(WIND.event.key.code, fight, obj);
    }
    if (WIND.event.type == sfEvtClosed)
        sfRenderWindow_close(WIND.wind);
    return 0;
}