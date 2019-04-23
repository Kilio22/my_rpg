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
        update_fight_text(rpg, 1, fight);
    vect.y += 15;
    vect.x += 80;
    sfText_setPosition(fight->text, vect);
    vect.y -= 15;
    vect.x -= 20;
    sfSprite_setPosition(fight->parch, vect);
}

void fight_action(rpg_t *rpg, obj_t **obj, house_t **house, fight_t *fight)
{
    if (check_characters_clock(obj[1]->clock, 10000.0) == 0) {
        all_character_animation(obj);
    }
    sfSprite_setPosition(obj[1]->sprite,
    sfSprite_getPosition(obj[HERO_HB]->sprite));
    camera_control(rpg, obj[HERO_HB]->pos, obj);
    update_all_rect(obj, house);
    update_text_pos(fight, rpg);
}

void fight_event_management(rpg_t *rpg)
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
            MENU.menu_on = 0;
    }
    if (WIND.event.type == sfEvtClosed)
        sfRenderWindow_close(WIND.wind);
}