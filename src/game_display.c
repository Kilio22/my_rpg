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
    sfRenderWindow_drawSprite(WIND.wind, obj[0]->sprite, NULL); //ground
    sfRenderWindow_drawSprite(WIND.wind, obj[1]->sprite, NULL); //hero_hitBox
    for (int i = 0; house[i] != NULL; i++) {
        sfRenderWindow_drawSprite(WIND.wind, house[i]->interior, NULL); //house_Interior
        if (house[i]->display_house == 1) {
            sfRenderWindow_drawSprite(WIND.wind, house[i]->wall, NULL); //house_Wall
            sfRenderWindow_drawSprite(WIND.wind, house[i]->door, NULL); //house_Door
        }
    }
    for (int i = 4; i > 1; i--)
        sfRenderWindow_drawSprite(WIND.wind, obj[i]->sprite, NULL); //obj
    for (int i = 0; house[i] != NULL; i++)
        if (house[i]->display_house == 1)
            sfRenderWindow_drawSprite(WIND.wind, house[i]->roof, NULL); //house_Roof
    sfRenderWindow_display(WIND.wind);
    sfRenderWindow_clear(WIND.wind, sfBlack);
}

static void game_loop(rpg_t *rpg, obj_t **obj, house_t **house)
{
    if (CONTROLS.bools[KEYSPACE] == 1) // setPosition of the character on camera
        sfSprite_setPosition(obj[1]->sprite, sfView_getCenter(WIND.view));
    character_control(rpg, obj[1], house);
    follower(obj, rpg);
    all_character_animation(obj);
    sfSprite_setPosition(obj[2]->sprite, sfSprite_getPosition(obj[1]->sprite));
    house_interaction(obj[1], house, rpg);
    camera_control(rpg, obj[1]->pos);
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