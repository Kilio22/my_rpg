/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** fight_events
*/

#include "rpg.h"

static int manage_key_enter(int code, fight_t *fight)
{
    if (code == sfKeyReturn && fight->fight_status == 0
&& fight->life[0] > 0 && fight->life[1] > 0) {
        if (fight->high == 2)
            return 1;
        fight->fight_status = 1;
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
        if (WIND.event.key.code == sfKeyF12)
            screenshot(rpg);
        if (WIND.event.key.code == sfKeyEscape
&& fight->life[0] > 0 && fight->life[1] > 0)
            pause_game(rpg);
        return manage_other_key_press(WIND.event.key.code, fight);
    }
    if (WIND.event.type == sfEvtClosed)
        sfRenderWindow_close(WIND.wind);
    if (MENU.menu_on == 0)
        return 1;
    return 0;
}