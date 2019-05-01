/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** new_game
*/

#include "rpg.h"

void menu_new_game(rpg_t *rpg, obj_t **obj, house_t **house)
{
    load_game_t load = init_load_game(rpg);
    int ret_val = 0;
    size_t frames;

    while (sfRenderWindow_isOpen(WIND.wind)) {
        while (sfRenderWindow_pollEvent(WIND.wind, &WIND.event))
            ret_val += check_new_game_events(rpg, &load, obj, house);
        if (ret_val == 1 || MENU.menu_on == 0) {
            destroy_load(&load);
            return;
        }
        rpg->frame = update_time(&frames);
        update_rect_load(&load, frames);
        check_mbutton_press_new(rpg, &load, obj, house);
        load_display(rpg, &load);
    }
    destroy_load(&load);
}