/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** menu_fcts
*/

#include "rpg.h"

void menu_credit(rpg_t *rpg, obj_t **obj, house_t **house)
{
    (void) rpg;
    (void) obj;
    (void) house;
}

void menu_how_to_play(rpg_t *rpg, obj_t **obj, house_t **house)
{
    (void) rpg;
    (void) obj;
    (void) house;
}

void menu_load_game(rpg_t *rpg, obj_t **obj, house_t **house)
{
    sfRenderWindow_clear(WIND.wind, sfBlack);
    sfRenderWindow_drawSprite(WIND.wind, MENU.menu_sprite[LOAD], NULL);
    sfRenderWindow_display(WIND.wind);
    init_game(rpg, obj, house);
    init_save(obj, rpg);
}

void menu_new_game(rpg_t *rpg, obj_t **obj, house_t **house)
{
    sfRenderWindow_clear(WIND.wind, sfBlack);
    sfRenderWindow_drawSprite(WIND.wind, MENU.menu_sprite[LOAD], NULL);
    sfRenderWindow_display(WIND.wind);
    init_game(rpg, obj, house);
    init_save(obj, rpg);
}

void menu_close_window(rpg_t *rpg, obj_t **obj, house_t **house)
{
    (void) obj;
    (void) house;
    sfRenderWindow_close(WIND.wind);
}