/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** game_display
*/

#include "rpg.h"

static void display(rpg_t *rpg, obj_t **obj, house_t **house)
{
    sfRenderWindow_setView(WIND.wind, WIND.view);
    sfRenderWindow_drawSprite(WIND.wind, obj[GROUND]->sprite, NULL);
    sfRenderWindow_drawSprite(WIND.wind, obj[HERO_HB]->sprite, NULL);
    house_display(rpg, house);
    for (int i = 4; i > 1; i--)
        sfRenderWindow_drawSprite(WIND.wind, obj[i]->sprite, NULL);
    for (int i = 0; house[i] != NULL; i++)
        if (house[i]->display_house == 1)
            sfRenderWindow_drawSprite(WIND.wind, house[i]->tab[ROOF], NULL);
    sfRenderWindow_display(WIND.wind);
    sfRenderWindow_clear(WIND.wind, sfBlack);
}

static void game_loop(rpg_t *rpg, obj_t **obj, house_t **house)
{
    character_control(rpg, obj[HERO_HB], house);
    follower(obj, rpg);
    all_character_animation(obj);
    sfSprite_setPosition(obj[2]->sprite,
sfSprite_getPosition(obj[HERO_HB]->sprite));
    house_interaction(obj[HERO_HB], house, rpg);
    camera_control(rpg, obj[HERO_HB]->pos, obj);
    update_all_rect(obj, house);
}

void init_game_loop(rpg_t *rpg, obj_t **obj, house_t **house)
{
    while (sfRenderWindow_isOpen(WIND.wind)) {
        while (sfRenderWindow_pollEvent(WIND.wind, &WIND.event))
            event_management(rpg, obj);
        if (MENU.menu_on == 0) {
            MENU.menu_on = 1;
            free_save(obj, rpg);
            return;
        }
        game_loop(rpg, obj, house);
        display(rpg, obj, house);
    }
}