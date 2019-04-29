/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** fight_events
*/

#include "rpg.h"

static int manage_key_enter(int code, fight_t *fight)
{
<<<<<<< HEAD
    sfVector2f vect = sfRenderWindow_mapPixelToCoords(WIND.wind,
(sfVector2i){0, 558}, WIND.view);

    if (fight->old_i == fight->nb_fight)
        update_fight_text(1, fight, 0, rpg);
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
=======
    if (code == sfKeyReturn && fight->fight_status == 0
&& fight->life[0] > 0 && fight->life[1] > 0) {
        if (fight->high == 2)
            return 1;
        fight->fight_status = 1;
>>>>>>> 3c29a41e0891e333dd55a7c70442afa45247a24c
    }
    return 0;
}

static int manage_other_key_press(int code, fight_t *fight)
{
    if (fight->quest_status < 3)
        return 0;
    if (code == sfKeyLeft && fight->high > 0 &&
fight->fight_status == 0 && fight->turn < 6
&& fight->life[0] > 0 && fight->life[1] > 0) {
        sfText_setColor(fight->attacks[fight->high], sfRed);
        fight->high--;
        sfText_setColor(fight->attacks[fight->high], sfBlue);
    }
    if (code == sfKeyRight && fight->high < 2 &&
fight->fight_status == 0 && fight->turn < 6
&& fight->life[0] > 0 && fight->life[1] > 0) {
        sfText_setColor(fight->attacks[fight->high], sfRed);
        fight->high++;
        sfText_setColor(fight->attacks[fight->high], sfBlue);
    }
    return manage_key_enter(code, fight);
}

int fight_event_management(rpg_t *rpg, fight_t *fight)
{
    if (WIND.event.type == sfEvtMouseMoved) {
        CONTROLS.mousePos.x = WIND.event.mouseMove.x;
        CONTROLS.mousePos.y = WIND.event.mouseMove.y;
    }
    if (WIND.event.type == sfEvtKeyPressed) {
        if (WIND.event.key.code == sfKeyF5)
            set_music(rpg);
        if (WIND.event.key.code == sfKeyEscape
&& fight->life[0] > 0 && fight->life[1] > 0)
            return 1;
        return manage_other_key_press(WIND.event.key.code, fight);
    }
    if (WIND.event.type == sfEvtClosed)
        sfRenderWindow_close(WIND.wind);
    return 0;
}