/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** game_display
*/

#include "rpg.h"

static void display_auberge(rpg_t *rpg, sfVector2f pos)
{
    sfText *text = create_text("assets/Augusta.ttf", auberge_dial[0], 25, V2F(pos.x - 175, pos.y - 180));
    sfText *text1 = create_text("assets/Augusta.ttf", auberge_dial[1], 25, V2F(pos.x - 125, pos.y - 160));
    sfText *text2 = create_text("assets/Augusta.ttf", auberge_dial[2], 25, V2F(pos.x - 85, pos.y - 140));
    sfText *text3 = create_text("assets/Augusta.ttf", auberge_dial[3], 25, V2F(pos.x - 95, pos.y - 120));
    sfText *text4 = create_text("assets/Augusta.ttf", auberge_dial[4], 25, V2F(pos.x - 44, pos.y - 100));

    sfRenderWindow_drawText(WIND.wind, text, NULL);
    sfRenderWindow_drawText(WIND.wind, text1, NULL);
    sfRenderWindow_drawText(WIND.wind, text2, NULL);
    sfRenderWindow_drawText(WIND.wind, text3, NULL);
    sfRenderWindow_drawText(WIND.wind, text4, NULL);
    sfText_destroy(text);
    sfText_destroy(text1);
    sfText_destroy(text2);
    sfText_destroy(text3);
    sfText_destroy(text4);
}

static void display_auberge2(rpg_t *rpg, sfVector2f pos)
{
    sfVector2f new_pos;
    sfText *text;

    if (GAME.auberge == 2) {
        new_pos.x = pos.x - 190;
        new_pos.y = pos.y - 180;
    }
    if (GAME.auberge == 3) {
        new_pos.x = pos.x - 260;
        new_pos.y = pos.y - 180;
    }
    text = create_text("assets/Augusta.ttf", auberge_action[GAME.auberge - 2], 25, new_pos);
    sfRenderWindow_drawText(WIND.wind, text, NULL);
    sfText_destroy(text);
}

static void other_display(rpg_t *rpg, sfVector2f pos)
{
    if (GAME.auberge == 1)
        display_auberge(rpg, pos);
    if (GAME.auberge > 1)
        display_auberge2(rpg, pos);
}

static void display(rpg_t *rpg, obj_t **obj, house_t **house)
{
    (void) house;
    sfRenderWindow_setView(WIND.wind, WIND.view);
    print_map(MAP.sprite, obj, rpg->wind);
    //sfRenderWindow_drawSprite(WIND.wind, obj[HERO_HB]->sprite, NULL);
    house_display(rpg, house);
    other_display(rpg, obj[1]->pos);
    for (int i = 3; i > 0; i--)
        sfRenderWindow_drawSprite(WIND.wind, obj[i]->sprite, NULL);
    for (int i = 0; house[i] != NULL; i++)
        if (house[i]->display_house == 1)
            sfRenderWindow_drawSprite(WIND.wind, house[i]->tab[ROOF], NULL);
    sfRenderWindow_display(WIND.wind);
    sfRenderWindow_clear(WIND.wind, sfBlack);
}

static void game_action(rpg_t *rpg, obj_t **obj, house_t **house)
{
    if (check_characters_clock(obj[1]->clock, 10000.0) == 0) {
        character_control(rpg, obj[HERO_HB], house);
        follower(obj, rpg);
        all_character_animation(obj);
    }
    sfSprite_setPosition(obj[1]->sprite,
    sfSprite_getPosition(obj[HERO_HB]->sprite));
    house_interaction(obj[HERO_HB], house, rpg);
    camera_control(rpg, obj[HERO_HB]->pos, obj);
    update_all_rect(obj, house);
}

void game_loop(rpg_t *rpg, obj_t **obj, house_t **house)
{
    sfVector2u windSize = sfRenderWindow_getSize(WIND.wind);

    sfClock_restart(obj[1]->clock);
    while (sfRenderWindow_isOpen(WIND.wind)) {
        while (sfRenderWindow_pollEvent(WIND.wind, &WIND.event))
            event_management(rpg, obj);
        if (MENU.menu_on == 0) {
            MENU.menu_on = 1;
            sfView_destroy(WIND.view);
            WIND.view =
sfView_createFromRect((sfFloatRect){0, 0, windSize.x, windSize.y});
            free_save(obj, rpg);
            return;
        }
        game_action(rpg, obj, house);
        display(rpg, obj, house);
    }
}