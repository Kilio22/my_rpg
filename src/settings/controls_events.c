/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** controls_events
*/

#include "rpg.h"

static void check_already_ctrl(rpg_t *rpg, int code)
{
    for (int i = 0; i < NB_KEYS; i++) {
        if (CONTROLS.keys[i] == code) {
            CONTROLS.keys[i] = -1;
            sfText_setString(CONTROLS.text[i].text, "N/A");
        }
    }
}

static void manage_move_event_ctrl(rpg_t *rpg, int *high)
{
    int i = check_mousepos_intersect(rpg, CONTROLS.text, NB_KEYS);

    WIND.mouse_pos.x = WIND.event.mouseMove.x;
    WIND.mouse_pos.y = WIND.event.mouseMove.y;
    if (i == -1) {
        sfText_setColor(CONTROLS.text[*high].text, sfRed);
        return;
    }
    sfText_setColor(CONTROLS.text[*high].text, sfRed);
    *high = i;
    sfText_setColor(CONTROLS.text[*high].text, sfYellow);
}

static void manage_key_pressed_ctrl(rpg_t *rpg, int code)
{
    if (code == -1 || CONTROLS.wait_key == -1 || code == sfKeyF6
|| code == sfKeyF12 || code == sfKeyF5 ||
code == sfKeyEscape || code == sfKeyReturn || code >= 101)
        return;
    check_already_ctrl(rpg, code);
    CONTROLS.keys[CONTROLS.wait_key] = code;
    sfText_setString(CONTROLS.text[CONTROLS.wait_key].text, key_str[code]);
    CONTROLS.wait_key = -1;
}

static void manage_mouse_click_ctrl(rpg_t *rpg, int code, int *high)
{
    if (code != 0)
        return;
    if (check_mousepos_intersect(rpg, CONTROLS.text, NB_KEYS) >= 0
&& CONTROLS.wait_key == -1) {
        sfText_setString(CONTROLS.text[*high].text, "PRESS ANY KEY");
        CONTROLS.wait_key = *high;
    }
}

int manage_control_events(rpg_t *rpg, int *high)
{
    if (WIND.event.type == sfEvtClosed)
        sfRenderWindow_close(WIND.wind);
    if (WIND.event.type == sfEvtKeyPressed &&
WIND.event.key.code == sfKeyEscape)
        return 1;
    if (WIND.event.type == sfEvtMouseMoved)
        manage_move_event_ctrl(rpg, high);
    if (WIND.event.type == sfEvtMouseButtonPressed)
        manage_mouse_click_ctrl(rpg, WIND.event.mouseButton.button, high);
    if (WIND.event.type == sfEvtKeyPressed)
        manage_key_pressed_ctrl(rpg, WIND.event.key.code);
    return 0;
}