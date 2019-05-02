/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** game_display
*/

#include "rpg.h"

void check_pnj_display(house_t **house, obj_t **obj, rpg_t *rpg)
{
    for (int i = 0; house[i] != NULL; i++) {
        if (house[i]->type == 2 && obj[5] == NULL
&& house[i]->display_house == 0) {
            obj[5] = create_object(obj_path[5], AUB_POS, RECT_OBJ, sfTrue);
            obj[5]->rectangle = sfRectangleShape_create();
            sfSprite_setOrigin(obj[5]->sprite, V2F(16, 60));
            sfRectangleShape_setSize(obj[5]->rectangle, V2F(32, 16));
            sfRectangleShape_setOrigin(obj[5]->rectangle, V2F(16, 8));
            sfRectangleShape_setPosition(obj[5]->rectangle, obj[5]->pos);
            obj[5]->rectangle_bound =
sfRectangleShape_getGlobalBounds(obj[5]->rectangle);
        }
        if (house[i]->type == 2 && obj[5] != NULL
&& house[i]->display_house == 1) {
            free_obj(obj[5]);
            obj[5] = NULL;
        }
        if (house[i]->display_house == 1)
            sfRenderWindow_drawSprite(WIND.wind, house[i]->tab[ROOF], NULL);
    }
}

void display(rpg_t *rpg, obj_t **obj, house_t **house)
{
    sfRenderWindow_clear(WIND.wind, sfBlack);
    sfRenderWindow_setView(WIND.wind, WIND.view);
    print_map(MAP.sprite, obj, rpg->wind);
    house_display(rpg, house);
    if (house[1]->display_house == 1)
        display_framebuffer(rpg);
    check_obj_display(obj, rpg);
    print_map2(MAP.sprite, obj, rpg->wind);
    check_pnj_display(house, obj, rpg);
    sfRenderWindow_display(WIND.wind);
}

static void game_action(rpg_t *rpg, obj_t **obj, house_t **house)
{
    static int i = 0;

    character_control(rpg, obj, house);
    follower(obj, rpg);
    move_pnjs(obj, house);
    all_character_animation(obj);
    sfSprite_setPosition(obj[1]->sprite,
    sfSprite_getPosition(obj[HERO_HB]->sprite));
    house_interaction(obj[HERO_HB], house, rpg);
    camera_control(rpg, obj[HERO_HB]->pos, obj);
    update_all_rect(obj, house);
    if (i > 9)
        check_end_game(rpg, obj, house);
    if (i < 10)
        i++;
}

void game_loop(rpg_t *rpg, obj_t **obj, house_t **house)
{
    sfVector2u windSize = sfRenderWindow_getSize(WIND.wind);
    size_t frames;

    sfClock_restart(obj[1]->clock);
    while (sfRenderWindow_isOpen(WIND.wind)) {
        rpg->frame = update_time(&frames);
        while (sfRenderWindow_pollEvent(WIND.wind, &WIND.event)
&& rpg->controls.bools[EVENTLOCK] == 0)
            event_management(rpg);
        if (MENU.menu_on == 0) {
            MENU.menu_on = 1;
            sfView_destroy(WIND.view);
            WIND.view =
sfView_createFromRect((sfFloatRect){0, 0, windSize.x, windSize.y});
            free_map(MAP);
            free_objs(obj);
            return;
        }
        game_action(rpg, obj, house);
        display(rpg, obj, house);
    }
}