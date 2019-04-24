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
(sfVector2i){0, 558}, WIND.view);;

    if (fight->old_i == fight->nb_fight)
        update_fight_text(1, fight, 0);
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
    sfVector2f vect2 = {13590, 440};
    sfVector2f vect3 = {13590, 560};
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
    if (check_characters_clock(obj[1]->clock, 10000.0) == 0) {
        all_character_animation(obj);
    }
    update_perso_pos(obj, fight);
    for (int i = 0; i < 5; i++)
        update_attacks_pos(fight, rpg, i);
    update_attacks_pos(fight, rpg, -1);
    sfSprite_setPosition(obj[1]->sprite,
    sfSprite_getPosition(obj[HERO_HB]->sprite));
    camera_control(rpg, obj[HERO_HB]->pos, obj);
    update_all_rect(obj, house);
    update_text_pos(fight, rpg);
    update_fondu_rect_fight(fight, rpg, 0);
}

void manage_other_key_press(int code, fight_t *fight)
{
    if (fight->quest_status < 3)
        return;
    if (code == sfKeyLeft && fight->high > 0) {
        sfText_setColor(fight->attacks[fight->high], sfRed);
        fight->high--;
        sfText_setColor(fight->attacks[fight->high], sfBlue);
    }
    if (code == sfKeyRight && fight->high < 4) {
        sfText_setColor(fight->attacks[fight->high], sfRed);
        fight->high++;
        sfText_setColor(fight->attacks[fight->high], sfBlue);
    }
}

int fight_event_management(rpg_t *rpg, fight_t *fight)
{
    if (WIND.event.type == sfEvtMouseWheelMoved)
        mouse_wheel_management(rpg);
    if (WIND.event.type == sfEvtMouseMoved) {
        CONTROLS.mousePos.x = WIND.event.mouseMove.x;
        CONTROLS.mousePos.y = WIND.event.mouseMove.y;
    }
    if (WIND.event.type == sfEvtKeyPressed) {
        if (WIND.event.key.code == sfKeyF5)
            set_music(rpg);
        if (WIND.event.key.code == sfKeyEscape)
            return 1;
        manage_other_key_press(WIND.event.key.code, fight);
    }
    if (WIND.event.type == sfEvtClosed)
        sfRenderWindow_close(WIND.wind);
    return 0;
}