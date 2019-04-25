/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** settings_events
*/

#include "rpg.h"

static int check_text_settings(settings_t *settings, int j)
{
    sfText_setColor(settings->text[3].text, sfRed);
    check_high_controls(0);
    if (j != 9)
        return 0;
    check_high_controls(1);
    sfText_setColor(settings->text[3].text, sfBlue);
    return 1;
}

static void analyse_settings_move(rpg_t *rpg, settings_t *settings)
{
    int i = check_mousepos_butt_set(rpg, settings);

    if (check_text_settings(settings, i) == 1)
        return;
    if (settings->buttons[i].state == 1)
        return;
    if (i < 3 && i > 0 && settings->buttons[i].state == 0) {
        sfSprite_setColor(settings->buttons[settings->high].sprite, sfWhite);
        sfSprite_setColor(settings->buttons[i].sprite, sfYellow);
        settings->high = i;
    } else
        sfSprite_setColor(settings->buttons[settings->high].sprite, sfWhite);
    if (i >= 3) {
        sfRectangleShape_setOutlineColor(settings->rect, sfRed);
        sfRectangleShape_setPosition(settings->rect, settings_spr_pos[i]);
        settings->high = i;
    } else {
        sfRectangleShape_setOutlineColor(settings->rect, sfBlue);
        sfRectangleShape_setPosition(settings->rect,
settings_spr_pos[GAME.language + 3]);
    }
    settings->high = i;
}

static void analyse_button_press_setting(rpg_t *rpg, settings_t *settings,
                                                                int code)
{
    if (code != 0)
        return;
    if (settings->high >= 3) {
        sfRectangleShape_setOutlineColor(settings->rect, sfBlue);
        if (settings->high == 3)
            GAME.language = 0;
        if (settings->high == 4)
            GAME.language = 1;
    }
    if (check_high_controls(-1) == 1) {
        init_controls_menu(rpg);
        sfText_setColor(settings->text[3].text, sfRed);
        check_high_controls(0);
    }
}

static void analyse_button_real_setting(settings_t *settings, int code,
                                                            rpg_t *rpg)
{
    if (code != 0)
        return;
    for (int i = 1; i < 5; i++) {
        if (settings->buttons[i].state == 1 &&
check_mousepos_butt_set(rpg, settings) == i)
            sfSprite_setColor(settings->buttons[i].sprite, sfYellow);
        settings->buttons[i].state = 0;
    }
}

int manage_settings_events(rpg_t *rpg, sfEvent event, settings_t *settings)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(WIND.wind);
    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeyF5)
            set_music(rpg);
        if (event.key.code == sfKeyEscape)
            return 1;
    }
    if (event.type == sfEvtMouseMoved) {
        WIND.mouse_pos.x = event.mouseMove.x;
        WIND.mouse_pos.y = event.mouseMove.y;
        analyse_settings_move(rpg, settings);
    }
    if (event.type == sfEvtMouseButtonPressed)
        analyse_button_press_setting(rpg, settings, event.mouseButton.button);
    if (event.type == sfEvtMouseButtonReleased)
        analyse_button_real_setting(settings, event.mouseButton.button, rpg);
    return 0;
}