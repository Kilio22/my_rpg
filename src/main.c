/*
** EPITECH PROJECT, 2018
** main
** File description:
** description
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "rpg.h"

int main(void)
{
    rpg_t rpg;
    obj_t **obj = malloc(sizeof(obj_t *) * 10);
    house_t **house = malloc(sizeof(house_t *) * 10);

    rpg.wind.wind = create_window("test window", 10);
    sfVector2u windowSize = sfRenderWindow_getSize(rpg.wind.wind);
    rpg.wind.view = sfView_createFromRect((sfFloatRect){0, 0, windowSize.x * 0.6, windowSize.y * 0.6});
    rpg.menu.menu_on = 1;

    obj[0] = create_object("assets/demo_map.png", (sfVector2f){0, 0}, (sfIntRect){0, 0, 620, 620}, sfFalse);
    obj[1] = create_object("assets/hero_hitbox.png", (sfVector2f){0, 0}, (sfIntRect){0, 0, 32, 16}, sfTrue);
    obj[2] = create_object("assets/hero.png", (sfVector2f){0, 0}, (sfIntRect){0, 0, 32, 64}, sfFalse);
    obj[3] = create_object("assets/normal_dummy.png", (sfVector2f){-100, 0}, (sfIntRect){0, 0, 32, 64}, sfFalse);
    obj[4] = create_object("assets/stupid_nathan.png", (sfVector2f){-50, 0}, (sfIntRect){0, 0, 32, 64}, sfFalse);
    obj[5] = NULL;
    house[0] = create_house(0, (sfVector2f){0, 0});
    house[1] = create_house(1, (sfVector2f){200, 0});
    house[2] = create_house(0, (sfVector2f){500, 0});
    house[3] = create_house(1, (sfVector2f){0, 300});
    house[4] = create_house(0, (sfVector2f){300, 300});
    house[5] = NULL;

    sfSprite_setOrigin(obj[2]->sprite, (sfVector2f){16, 60});
    sfSprite_setOrigin(obj[3]->sprite, (sfVector2f){16, 60});
    sfSprite_setOrigin(obj[4]->sprite, (sfVector2f){16, 60});

    rpg.game.nb_save = 0;
    rpg.controls.bools = malloc(sizeof(sfBool) * 9);
    for (int i = 0; i < 9; i++)
        rpg.controls.bools[i] = 0;
    rpg.wind.list = init_list(-50);
    rpg.wind.list2 = init_list(-100);
    init_menu(&rpg, obj, house);
    return (0);
}