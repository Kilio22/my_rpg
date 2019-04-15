/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** game_display
*/

#include "rpg.h"

char *my_ftoa(float value)
{
    int ent = value;
    int decimals = value * 100 - (ent * 100);
    char *string = my_itoa(ent, "");

    if (decimals != 0) {
        string = my_strncat(string, ".", -1);
        string = my_strncat(string, my_itoa(decimals, ""), -1);
    }
    return (string);
}

static void debug_txt(rpg_t *rpg, obj_t *obj)
{
    char *txt = my_strncat("", my_ftoa(obj->pos.x), -1);

    txt = my_strncat(txt, "  ", -1);
    txt = my_strncat(txt, my_ftoa(obj->pos.y), -1);
    sfText_setPosition(rpg->debug_txt, V2F(obj->pos.x + 240, obj->pos.y - 210));
    sfText_setString(rpg->debug_txt, txt);
    sfRenderWindow_drawText(WIND.wind, rpg->debug_txt, NULL);
}

static void display(rpg_t *rpg, obj_t **obj, house_t **house)
{
    sfRenderWindow_setView(WIND.wind, WIND.view);
    //print_map(MAP.sprite, obj, rpg->wind);
    //sfRenderWindow_drawSprite(WIND.wind, obj[HERO_HB]->sprite, NULL);
    sfRenderWindow_drawSprite(WIND.wind, obj[4]->sprite, NULL);
    house_display(rpg, house);
    for (int i = 3; i > 0; i--)
        if (obj[i] != NULL)
            sfRenderWindow_drawSprite(WIND.wind, obj[i]->sprite, NULL);
    //print_map2(MAP.sprite, obj, rpg->wind);
    for (int i = 0; house[i] != NULL; i++)
        if (house[i]->display_house == 1)
            sfRenderWindow_drawSprite(WIND.wind, house[i]->tab[ROOF], NULL);
    if (rpg->debug == 1)
        debug_txt(rpg, obj[1]);
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
            //free_map(MAP);
            return;
        }
        game_action(rpg, obj, house);
        display(rpg, obj, house);
    }
}