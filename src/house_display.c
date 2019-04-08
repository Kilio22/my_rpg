/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** house_display
*/

#include "rpg.h"

void do_not_display_house(obj_t *obj, house_t *house, rpg_t *rpg)
{
    sfSprite_move(obj->sprite, (sfVector2f){0, 1});
    if (pp_intersect(obj->sprite, house->tab[HITBOX],
obj->image, house->image) == 0) {
        house->display_house = 1;
        CONTROLS.bools[KEYINTER] = 0;
    }
}

void display_house(obj_t *obj, house_t *house, rpg_t *rpg)
{
    if (house->frame_animation > 8 && house->door_rect.left < 384 - 96) {
        animation(&house->door_rect, 0, 96, 384);
        house->frame_animation = 0;
    }
    house->frame_animation++;
    if (house->door_rect.left > 384 - 97) {
        sfSprite_move(obj->sprite, (sfVector2f){0, -1});
        if (pp_intersect(obj->sprite, house->tab[HITBOX],
obj->image, house->image) == 0) {
            house->door_rect.left = 0;
            house->display_house = 0;
            CONTROLS.bools[KEYINTER] = 0;
        }
    }
}

void check_house_display(obj_t *obj, house_t *house, rpg_t *rpg)
{
    if (house->display_house == 1)
        display_house(obj, house, rpg);
    else
        do_not_display_house(obj, house, rpg);
}

void house_interaction(obj_t *obj, house_t **house, rpg_t *rpg)
{
    for (int i = 0; house[i] != NULL; i++)
        if (pp_intersect(obj->sprite, house[i]->tab[DOOR], obj->image,
house[i]->door_image) == 1 && CONTROLS.bools[KEYINTER] == 1)
            check_house_display(obj, house[i], rpg);
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