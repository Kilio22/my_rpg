/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** house_display
*/

#include "rpg.h"

void exit_house(obj_t *obj, house_t *house, rpg_t *rpg)
{
    sfSprite_move(obj->sprite, (sfVector2f){0, 1});
    sfRectangleShape_move(obj->rectangle, (sfVector2f){0, 1});
    obj->rectangle_bound = sfRectangleShape_getGlobalBounds(obj->rectangle);
    if (sfFloatRect_intersects(&obj->rectangle_bound, &house->door_use_rect_bound, NULL) == 0) {
        house->display_house = 1;
        CONTROLS.bools[KEYINTER] = 0;
        rpg->controls.bools[EVENTLOCK] = 0;
    }
}

void enter_house(obj_t *obj, house_t *house, rpg_t *rpg)
{
    if (house->frame_animation > 8 && house->door_rect.left < 288) {
        animation(&house->door_rect, 0, 96, 384);
        house->frame_animation = 0;
    }
    house->frame_animation++;
    if (house->door_rect.left >= 288) {
        sfSprite_move(obj->sprite, (sfVector2f){0, -1});
        sfRectangleShape_move(obj->rectangle, (sfVector2f){0, -1});
        obj->rectangle_bound = sfRectangleShape_getGlobalBounds(obj->rectangle);
        if (sfFloatRect_intersects(&obj->rectangle_bound, &house->door_use_rect_bound, NULL) == 0) {
            house->door_rect.left = 0;
            house->display_house = 0;
            CONTROLS.bools[KEYINTER] = 0;
            rpg->controls.bools[EVENTLOCK] = 0;
        }
    }
}

void check_house_display(obj_t *obj, house_t *house, rpg_t *rpg)
{
    if (house->display_house == 1) {
        enter_house(obj, house, rpg);
    }
    else
        exit_house(obj, house, rpg);
}

void house_interaction(obj_t *obj, house_t **house, rpg_t *rpg)
{
    for (int i = 0; house[i] != NULL; i++) {
        if (sfFloatRect_intersects(&obj->rectangle_bound, &house[i]->door_use_rect_bound, NULL) == 1 && CONTROLS.bools[KEYINTER] == 1) {
            rpg->controls.bools[EVENTLOCK] = 1;
            rpg->controls.bools[KEYDOWN] = 0;
            rpg->controls.bools[KEYLEFT] = 0;
            rpg->controls.bools[KEYRIGHT] = 0;
            rpg->controls.bools[KEYUP] = 0;
            check_house_display(obj, house[i], rpg);
        }
    }
}

void house_display(rpg_t *rpg, house_t **house)
{
    for (int i = 0; house[i] != NULL; i++) {
        sfRenderWindow_drawSprite(WIND.wind, house[i]->tab[INTERIOR], NULL);
        if (house[i]->display_house == 1) {
            sfRenderWindow_drawSprite(WIND.wind, house[i]->tab[WALL], NULL);
            sfRenderWindow_drawSprite(WIND.wind, house[i]->tab[DOOR], NULL);
        }
    }
}