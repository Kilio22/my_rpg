/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** menu
*/

#include "rpg.h"

static void display_menu(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(WIND.wind, MENU.menu_sprite[BACK], NULL);
    for (int i = 0; i < 6; i++)
        sfRenderWindow_drawText(WIND.wind, MENU.buttons[i].text, NULL);
    sfRenderWindow_setView(WIND.wind, WIND.view);
    sfRenderWindow_display(WIND.wind);
    sfRenderWindow_clear(WIND.wind, sfBlack);
}

void menu_loop(rpg_t *rpg, obj_t **obj, house_t **house)
{
    while (sfRenderWindow_isOpen(WIND.wind)) {
        while (sfRenderWindow_pollEvent(WIND.wind, &WIND.event))
            menu_event_management(rpg, obj, house);
        display_menu(rpg);
    }
}