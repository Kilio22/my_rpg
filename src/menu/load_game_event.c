/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** event_load_game
*/

#include "rpg.h"

void update_time(sfTime *current_time, sfTime *old_time, rpg_t *rpg,
                                                        size_t *frames)
{
    *current_time = sfClock_getElapsedTime(MENU.clock);
    *frames =
sfTime_asMicroseconds(*current_time) - sfTime_asMicroseconds(*old_time);
    *frames /= 1000 / 60;
    *frames /= 1000;
    (*old_time).microseconds = (*current_time).microseconds;
}

void check_mbutton_press_load(rpg_t *rpg, load_game_t *load, obj_t **obj,
                                                            house_t **house)
{
    int i = check_mousepos_intersect(rpg, load->text, 3);

    if (!sfMouse_isButtonPressed(0))
        return;
    if (i == -1)
        return;
    GAME.nb_save = i;
    init_save(obj, rpg);
    sfRenderWindow_drawSprite(WIND.wind, MENU.menu_sprite[LOAD], NULL);
    sfRenderWindow_display(WIND.wind);
    init_game(rpg, obj, house);
}

void check_move_load(rpg_t *rpg, load_game_t *load)
{
    int j = check_mousepos_intersect(rpg, load->text, 3);

    if (j == -1)
        return;
    for (int i = 0; i < 3; i++)
        sfText_setColor(load->text[i].text, sfRed);
    load->high = j;
    sfText_setColor(load->text[j].text, sfYellow);
}

int check_button_pressed_load(rpg_t *rpg, load_game_t *load, obj_t **obj,
                                                        house_t **house)
{
    if (WIND.event.key.code == sfKeyEscape)
        return 1;
    if (WIND.event.key.code == sfKeyDown && load->high < 2)
        load->high++;
    if (WIND.event.key.code == sfKeyUp && load->high > 0)
        load->high--;
    for (int i = 0; i < 3; i++)
        sfText_setColor(load->text[i].text, sfRed);
    sfText_setColor(load->text[load->high].text, sfYellow);
    if (WIND.event.key.code == sfKeyReturn) {
        GAME.nb_save = load->high;
        init_save(obj, rpg);
        sfRenderWindow_drawSprite(WIND.wind, MENU.menu_sprite[LOAD], NULL);
        sfRenderWindow_display(WIND.wind);
        init_game(rpg, obj, house);
        return 1;
    }
    return 0;
}

int check_load_game_events(rpg_t *rpg, load_game_t *load, obj_t **obj,
                                                        house_t **house)
{
    int ret_val = 0;

    if (WIND.event.type == sfEvtClosed)
        sfRenderWindow_close(WIND.wind);
    if (WIND.event.type == sfEvtMouseMoved) {
        WIND.mouse_pos.x = WIND.event.mouseMove.x;
        WIND.mouse_pos.y = WIND.event.mouseMove.y;
        check_move_load(rpg, load);
    }
    if (WIND.event.type == sfEvtKeyPressed)
        ret_val += check_button_pressed_load(rpg, load, obj, house);
    return ret_val;
}