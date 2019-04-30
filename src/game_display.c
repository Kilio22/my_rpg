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

static void check_pos_objs(obj_t **obj, int *n_val)
{
    float lowest_dist = -1;

    for (int i = 5; i < 9; i++) {
        if (obj[i] == NULL)
            continue;
        lowest_dist = calc_dist(obj[0]->pos, obj[i]->pos);
        *n_val = i;
        break;
    }
    if (lowest_dist == -1)
        return;
    for (int i = *n_val + 1; i < 9; i++) {
        if (obj[i] == NULL)
            continue;
        if (calc_dist(obj[0]->pos, obj[i]->pos) < lowest_dist) {
            *n_val = i;
            lowest_dist = calc_dist(obj[0]->pos, obj[i]->pos);
        }
    }
}

void check_obj_display(obj_t **obj, rpg_t *rpg)
{
    int n_val = -1;

    check_pos_objs(obj, &n_val);
    if (n_val == -1) {
        print_reverse_order(obj, rpg);
        return;
    }
    if (obj[0]->pos.y >= obj[n_val]->pos.y)
        n_val = -1;
    if (n_val > 0)
        print_reverse_order(obj, rpg);
    else
        print_base_order(obj, rpg);
}

void display(rpg_t *rpg, obj_t **obj, house_t **house)
{
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
    character_control(rpg, obj, house);
    follower(obj, rpg);
    move_pnjs(obj, house);
    all_character_animation(obj);
    sfSprite_setPosition(obj[1]->sprite,
    sfSprite_getPosition(obj[HERO_HB]->sprite));
    house_interaction(obj[HERO_HB], house, rpg);
    camera_control(rpg, obj[HERO_HB]->pos, obj);
    update_all_rect(obj, house);
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
        sfRenderWindow_clear(WIND.wind, sfBlack);
        display(rpg, obj, house);
    }
}